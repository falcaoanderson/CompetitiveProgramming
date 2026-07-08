/*
21/02/26 

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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

vector<vector<int>> adj, memo, parent; 
vector<int> tree, pos;

void dfs(int u){
    tree.PB(u);
    pos[u] = (int)tree.size() - 1;

    if(adj[u].empty()){
        memo[u][0] = 1;
        return;
    }

    memo[u][0] = 3;
    for(int v: adj[u]){
        dfs(v);

        tree.PB(u);

        parent[v][0] = u;
        memo[u][0] += memo[v][0];
        memo[u][0] = min(memo[u][0], MOD+1);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;

    adj.assign(n+1, vector<int>(0));
    memo.assign(n+1, vector<int>(20, MOD+1));
    parent.assign(n+1, vector<int>(20, 0));
    tree.clear();
    pos.assign(n+1, 0);

    // cout << "arestas:" << endl;
    for(int i=1; i<=n; i++){
        int l, r;
        cin >> l >> r;
        
        if(l !=0 || r !=0){
            adj[i].PB(l);
            adj[i].PB(r);
            // cout << i << " " << l << endl;
            // cout << i << " " << r << endl;
        }
    }
    // cout << "fim arestas" << endl;

    dfs(1);
    // cout << "tree: ";
    // for(int x: tree) cout << x << " ";
    // cout << endl;

    for(int k=1; k<=18; k++){
        for(int u=1; u<=n; u++){
            parent[u][k] = parent[parent[u][k-1]][k-1],
            memo[u][k] = memo[u][k-1] + memo[parent[u][k-1]][k-1];
            memo[u][k] = min(memo[u][k], MOD+1);

            // if(parent[u][k]!=0){
            //     cout << "parent[" << u << "][" << k << "] = " << parent[u][k] << endl;
            //     cout << "memo[" << u << "][" << k << "] = " << memo[u][k] << endl;
            // }
        }
    }

    // cout << "resposta: ";
    while(q--){
        int u, t;
        cin >> u >> t;
        
        // cout << "antes/depois: " << t;
        for(int k=18; k>=0; k--){
            int p = parent[u][k], delta = memo[u][k]; 
            
            if(p != 0 && t >= delta){
                u = p;
                t -= delta;
            }
        }
        // cout << " " << t << endl;

        if( pos[u] + t < (int)tree.size())
            cout << tree[pos[u] + t] << " ";
        else 
            cout << -1 << " ";
    }
    cout << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
