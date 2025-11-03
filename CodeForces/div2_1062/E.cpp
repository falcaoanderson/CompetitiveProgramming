/*
23/10/25 

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
const ll MOD  = (1e9) + 7;

vector<int> adj[MAXN];
int tt=0, in[MAXN], out[MAXN], lvl[MAXN];
int parent[MAXN][16 + 5], st_min[MAXN][16+5], st_max[MAXN][16+5];

void dfs(int u){
    for(int k=1; (1<<k)<=lvl[u]; k++){
        parent[u][k] = parent[parent[u][k-1]][k-1];
    }

    in[u] = (++tt);
    for(int v: adj[u]){
        lvl[v] = lvl[u] + 1;
        parent[v][0] = u;
        dfs(v);
    }
    out[u] = (++tt);
}

int lca(int u, int v){
    if(in[u] <= in[v] && in[v] <= out[u]) return u;
    if(in[v] <= in[u] && in[u] <= out[v]) return v;

    for(int k=16; k>=0; k--){
        if(parent[u][k]!=0 && !(in[parent[u][k]]<=in[v] && in[v]<=out[parent[u][k]])){
            u = parent[u][k];
        }
    }
    return parent[u][0];
}

void start_st(int n){
    for(int i=1; i<=n; i++){
        st_min[i][0] = st_max[i][0] = i;
    }
    for(int k=1; (1<<k)<=n; k++){
        for(int l=1; l+(1<<k)-1<=n; l++){
            int r = l+(1<<k)-1;

            if(in[st_min[l][k-1]] <= in[st_min[(l+r)/2+1][k-1]]){
                st_min[l][k] = st_min[l][k-1];
            }
            else{
                st_min[l][k] = st_min[(l+r)/2+1][k-1];
            }

            if(in[st_max[l][k-1]] >= in[st_max[(l+r)/2+1][k-1]]){
                st_max[l][k] = st_max[l][k-1];
            }
            else{
                st_max[l][k] = st_max[(l+r)/2+1][k-1];
            }
        }
    }
}

int query_max(int l, int r){
    int k = log2(r-l+1);

    if(in[st_max[l][k]] >= in[st_max[r-(1<<k)+1][k]]){
        return st_max[l][k];
    }
    else{
        return st_max[r-(1<<k)+1][k];
    }
}

int query_min(int l, int r){
    int k = log2(r-l+1);

    if(in[st_min[l][k]] <= in[st_min[r-(1<<k)+1][k]]){
        return st_min[l][k];
    }
    else{
        return st_min[r-(1<<k)+1][k];
    }
}

pii query_pair_max(int l, int r){
    int idx_max = query_max(l, r);
    int left_max=-1, right_max=-1, idx_snd_max;

    if(idx_max>l) left_max  = query_max(l, idx_max-1);
    if(idx_max<r) right_max = query_max(idx_max+1, r);

    if(left_max==-1) idx_snd_max = right_max;
    else if(right_max==-1) idx_snd_max = left_max;
    else if(in[left_max] >= in[right_max]) idx_snd_max = left_max;
    else idx_snd_max = right_max;

    return {idx_max, idx_snd_max};
}

pii query_pair_min(int l, int r){
    int idx_min = query_min(l, r);
    int left_min=-1, right_min=-1, idx_snd_min;

    if(idx_min>l) left_min  = query_min(l, idx_min-1);
    if(idx_min<r) right_min = query_min(idx_min+1, r);

    if(left_min==-1) idx_snd_min = right_min;
    else if(right_min==-1) idx_snd_min = left_min;
    else if(in[left_min] <= in[right_min]) idx_snd_min = left_min;
    else idx_snd_min = right_min;

    return {idx_min, idx_snd_min};
}

int main(){
    fast_io;

    int n, q;
    cin >> n >> q;

    for(int i=2; i<=n; i++){
        int p;
        cin >> p;

        adj[p].PB(i);
    }

    dfs(1);
    start_st(n);

    while(q--){
        int l, r;
        cin >> l >> r;

        pii tmp = query_pair_max(l, r);
        int idx_fst_max = tmp.FF, idx_snd_max = tmp.SS;

        tmp = query_pair_min(l, r);
        int idx_fst_min = tmp.FF, idx_snd_min = tmp.SS;

        int in_max_rmv = lvl[lca(idx_snd_max, idx_fst_min)];
        int in_min_rmv = lvl[lca(idx_snd_min, idx_fst_max)];

        if(in_max_rmv >=  in_min_rmv){
            cout << idx_fst_max << " " << in_max_rmv << endl;
        }
        else{
            cout << idx_fst_min << " " << in_min_rmv << endl;;
        }
    }

    return 0;
}