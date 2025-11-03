/*
16/10/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;
const int LOGMAXN = 16;
const ll MOD  = (1e9) + 7;

int n, in[MAXN], out[MAXN], tt=0;
int parent[MAXN][LOGMAXN+5];
int qnt[MAXN], in_v[MAXN];
vector<int> adj[MAXN];

int bit[2*MAXN];
void bit_update(int idx, int val){
    while(idx<=2*n){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
int bit_query(int idx){
    int sum = 0; 
    while(idx>0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void dfs(int u, int p){
    in[u] = (++tt);
    
    for(int v: adj[u]){
        if(v == p) continue;
        parent[v][0] = u;
        dfs(v, u);
    }

    out[u] = (++tt);
}

bool is_parent(int u, int p){
    return in[p] < in[u] && out[u] < out[p];
}

void precompute_lca(){
    dfs(1, 0);

    for(int k=1; k<=LOGMAXN; k++){
        for(int u=1; u<=n; u++){
            parent[u][k] = parent[parent[u][k-1]][k-1];
        }
    }
}

int lca(int u, int v){
    if(is_parent(u, v)) return v;
    if(is_parent(v, u)) return u;

    for(int k=LOGMAXN; k>=0; k--){
        if(parent[u][k]!=0 && !is_parent(v, parent[u][k])){
            u = parent[u][k];
        }
    }

    return parent[u][0];
}

bool cmp(int u, int v){
    return qnt[u] < qnt[v]; 
}

int main(){
    fast_io;

    int q;
    cin >> n >> q;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    precompute_lca();
    
    vector<int> v;
    
    while(q--){
        int k, groups, root;
        cin >> k >> groups >> root;

        v.assign(k, 0);
        for(int i=0; i<k; i++){
            cin >> v[i];
            in_v[v[i]] = 1;
        }
        
        // calcula a quantidade de parentes
        for(int u: v){
            bit_update(in[u], 1);
            bit_update(out[u], -1);
        }
        
        int hroot = bit_query(in[root]);
        for(int u: v){
            int lca_u_root = lca(u, root);
            
            qnt[u] = bit_query(in[u]) + hroot - 2 * bit_query(in[lca_u_root]) + in_v[lca_u_root] - 1;
        }

        sort(v.begin(), v.end(), cmp);
        
        // Resolve DP
        vector<vector<ll>> memo(k+1, vector<ll>(groups+1));
        memo[1][1] = 1;

        for(int i=2; i<=k; i++){
            int u = v[i-1];

            for(int g=1; g<=groups && g<=i; g++){
                memo[i][g] = memo[i-1][g-1];

                if(g > qnt[u]){
                    memo[i][g] += (memo[i-1][g] * (ll)(g - qnt[u])) % MOD;
                    memo[i][g] %= MOD;
                }
            }
        }

        ll resp = 0;
        for(int g=1; g<=groups; g++) resp = (resp + memo[k][g]) % MOD;

        cout << resp << endl;

        // desfazer operacoes
        for(int u: v){
            bit_update(in[u], -1);
            bit_update(out[u], 1);

            in_v[u] = 0;
            qnt[u] = 0;
        }
    }

    return 0;
}
