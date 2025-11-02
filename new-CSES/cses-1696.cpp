/*
11/09/25 

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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

vector<int> adj[MAXN];
int flow[MAXN][MAXN];

int bfs(int st, int ed, vector<int>& parent){
    parent.assign(SZ(parent), -1);
    parent[0] = 0;
    queue<pii> fila;
    fila.push({st, INF});

    while(!fila.empty()){
        int u = fila.front().FF;
        int crr_flow = fila.front().SS;
        fila.pop();

        if(u==ed){
            return crr_flow;
        }

        for(int v: adj[u]){
            if(parent[v]!=-1 || flow[u][v]<=0) continue;

            parent[v] = u;
            fila.push({v, min(crr_flow, flow[u][v])});
        }
    }

    return 0;
}

int main(){
    fast_io;

    int n, m, k;
    cin >> n >> m >> k;

    int st = 0, ed = n+m+1;

    vector<pii> edges(k);
    for(int i=0; i<k; i++) cin >> edges[i].FF >> edges[i].SS;
    sort(edges.begin(), edges.end());

    for(int i=0; i<k; i++){
        if(i>0 && edges[i]==edges[i-1]) continue;
        int a = edges[i].FF, b = edges[i].SS;

        adj[a].PB(b+n);
        flow[a][b+n] = 1;
        adj[b+n].PB(a);
    }

    for(int i=1; i<=n; i++){
        adj[st].PB(i);
        flow[st][i] = 1;
        adj[i].PB(st);
    }
    for(int i=n+1; i<=n+m; i++){
        adj[i].PB(ed);
        flow[i][ed] = 1;
        adj[ed].PB(i);
    }

    vector<int> parent(n+m+2);
    int max_flow = 0;

    while(true){
        int crr_flow = bfs(st, ed, parent);
        if(crr_flow==0) break;

        max_flow += crr_flow;

        int v=ed;
        while(v!=st){
            int u = parent[v];
            
            flow[u][v] -= crr_flow;
            flow[v][u] += crr_flow;

            v = u;
        }
    }

    cout << max_flow << endl;

    for(int u=1; u<=n; u++){
        for(int v: adj[u]){
            if(v!=0 && flow[v][u]==1){
                cout << u << " " << v-n << endl;
            }
        }
    }

    return 0;
}
