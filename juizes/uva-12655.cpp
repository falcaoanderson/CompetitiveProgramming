/*
06/08/24 
Problem: 
Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e4) + 5;
const int MOD  = (1e9) + 7;

int n, m;
vector<pii> adj[MAXN];
int pai[MAXN], dist[MAXN];
int lvl[MAXN], parent[MAXN][23], min_edge[MAXN][23];

int find(int u){
    if(pai[pai[u]]==pai[u]) return pai[u];

    return pai[u] = find(pai[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return;

    if(dist[u]>dist[v]){
        pai[v] = u;
    }
    else{
        pai[u] = v;

        dist[u] += (dist[u]==dist[v]);
    }
}

void dfs(int u, int last){
    for(pii e: adj[u]){
        if(e.FF == last) continue;

        lvl[e.FF] = lvl[u]+1;
        parent[e.FF][0]   = u;
        min_edge[e.FF][0] = e.SS;

        dfs(e.FF, u);
    }
}

int min(int a, int b, int c){
    return min(a, min(b, c));
}

int lca(int u, int v){
    int resp = INF;

    if(lvl[u]<lvl[v]) swap(u, v);

    for(int k=17; k>=0; k--){
        if(parent[u][k]!=0 && lvl[ parent[u][k] ] >= lvl[v]){
            resp = min(resp, min_edge[u][k]);
            u = parent[u][k];
        }
    }

    if(u==v) return resp;

    for(int k=17; k>=0; k--){
        if(parent[u][k]!=parent[v][k]){
            resp = min(resp, min_edge[u][k], min_edge[v][k]);
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    
    resp = min(resp, min_edge[u][0], min_edge[v][0]);
    u = parent[u][0]; // LCA

    return resp;
}

int main(){
    fast_io;

    int q;
    while(cin >> n >> m >> q){
        if(n==0) break;

        vector<tiii> edges;

        memset(dist, 0, sizeof(dist));
        memset(parent, 0, sizeof(parent));
        memset(min_edge, 0, sizeof(min_edge));
        for(int i=1; i<=n; i++){
            pai[i] = i;
            adj[i].clear();
        }

        for(int i=0; i<m; i++){
            int a, b, w;
            cin >> a >> b >> w;
        
            edges.EB(w, a, b);
        }

        sort(edges.begin(), edges.end());

        for(int i=m-1; i>=0; i--){
            int a, b, w;
            tie(w, a, b) = edges[i];

            if(find(a)!=find(b)){
                adj[a].EB(b, w);
                adj[b].EB(a, w);

                merge(a, b);
            }
        }

        lvl[1] = 0;
        dfs(1, 0);

        for(int k=1; k<=17; k++){
            for(int u=1; u<=n; u++){
                parent[u][k] = parent[parent[u][k-1]][k-1];

                min_edge[u][k] = min(min_edge[u][k-1], min_edge[parent[u][k-1]][k-1]); 
            }
        }


        while(q--){
            int a, b;
            cin >> a >> b;

            cout << lca(a, b) << endl;
        }
    }

    return 0;
}