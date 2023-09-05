// 14/08/23 // 05/09/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define EB emplace_back
#define ff first
#define ss second
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = 1e5+5;
const int INF = 0x3f3f3f3f;

int n, m;
vector<pii> adj[MAXN];
int pai[MAXN], dist[MAXN]; // DSU

int find(int u){
    if(pai[u]==u) return u;

    return pai[u] = find(pai[u]);
}
void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return;

    if(dist[u]>=dist[v]){
        pai[v] = u;

        if(dist[u]==dist[v]) dist[u]++;
    }
    else{
        pai[u] = v;
    }
}

void dsu(){
    vector<tiii> edges;

    for(int i=0; i<m; i++){
        int u, v, p;
        cin >> u >> v >> p;

        edges.EB(p, u, v);
    }
    
    sort(edges.begin(), edges.end());
    
    for(int i=1; i<=n; i++) pai[i] = i;
    int qnt_edges=0;
    for(int i=m-1; i>=0 && qnt_edges<n-1; i--){
        int u, v, p;
        tie(p, u, v) = edges[i];

        if(find(u)!=find(v)){
            join(u, v);
            qnt_edges++;

            adj[u].EB(v, p);
            adj[v].EB(u, p);
        }
    }
}

int level[MAXN], anc[MAXN][20], qanc[MAXN][20];
void dfs1(int u, int last){
    for(pii edge: adj[u]){
        int v=edge.ff, w=edge.ss;
        if(v==last) continue;

        level[v] = level[u] + 1;
        anc[v][0] = u;
        qanc[v][0] = w;

        dfs1(v, u);
    }
}

int min(int a, int b, int c){
    return min(a, min(b, c));
}

int lca(int u, int v){
    if(u==v) return u;

    if(level[v]<level[u]) swap(u, v);

    int resp = INF;

    for(int k=16; k>=0; k--){
        if(anc[v][k]!=0 && level[anc[v][k]]>=level[u]){
            resp = min(resp, qanc[v][k]);
            v = anc[v][k];
        }
    }

    if(u==v) return resp;

    for(int k=16; k>=0; k--){
        if(anc[u][k]!=0 && anc[v][k]!=0 && anc[u][k]!=anc[v][k]){
            resp = min(resp, qanc[u][k], qanc[v][k]);
            
            u = anc[u][k];
            v = anc[v][k];
        }
    }

    resp = min(resp, qanc[u][0], qanc[v][0]);

    return resp;
}


int main(){
    fast_io;

    cin >> n >> m;

    dsu();

    // LCA
    dfs1(1, 0);

    for(int k=1; k<=16; k++){
        for(int i=1; i<=n; i++){
            anc[i][k] = anc[anc[i][k-1]][k-1];
            qanc[i][k] = min(qanc[i][k-1], qanc[anc[i][k-1]][k-1]);
        }
    }

    int q;
    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << endl;
    }

    return 0;
}