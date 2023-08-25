// 25/08/23 // subtask 1 e 2 // pega 66 pts 
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
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef pair< ll, int> pli;
typedef tuple<ll, int, int> tlii;

const ll  INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MAXK = (1e2) + 5;

int n, key[MAXN];
vector<pii> adj[MAXN][MAXK];
ll dist[MAXN][MAXK];

void dijkstra(int ini){    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=100; j++){
            dist[i][j] = INF;
        }
    }
    dist[1][key[1]] = 0;

    priority_queue< tlii, vector<tlii>, greater<tlii> > fila;
    fila.emplace(0LL, ini, key[1]);
    
    while(!fila.empty()){
        int u, k_u; ll dist_u;
        tie(dist_u, u, k_u) = fila.top();
        fila.pop();

        if(dist[u][k_u]!=dist_u) continue;

        for(pii edge: adj[u][k_u]){
            int v = edge.ff;
            ll  d = edge.ss;

            if(dist_u + d < dist[v][k_u]){
                dist[v][k_u] = dist_u + d;
                fila.emplace(dist[v][k_u], v, k_u);
            }
        }

        if(dist_u < dist[u][key[u]]){
            dist[u][key[u]] = dist_u;
            fila.emplace(dist[u][key[u]], u, key[u]);
        }
    }
}

int main(){
    fast_io;

    int m, k=0;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) cin >> key[i];

    for(int i=0; i<m; i++){
        int a, b, dist, ki;
        cin >> a >> b >> dist >> ki;

        adj[a][ki].EB(b, dist);
        adj[b][ki].EB(a, dist);
    }

    dijkstra(1);

    ll dist_n = INF;
    for(int i=0; i<=100; i++) dist_n = min(dist_n, dist[n][i]);

    cout << (dist_n<INF? dist_n: -1) << endl;

    return 0;
}
