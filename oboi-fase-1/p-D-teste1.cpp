// 13/08/23 //
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
typedef tuple<int, int, int> tiii;

const ll  INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;

int n, key[MAXN];
vector<tiii> adj[MAXN];
ll dist[MAXN];

void dijkstra(int ini){    
    for(int i=1; i<=n; i++) dist[i] = INF;

    priority_queue< pli, vector<pli>, greater<pli> > fila;
    fila.emplace(0LL, ini);

    while(!fila.empty()){
        int u=1;
        ll dist_u=INF;

        while(!fila.empty()){
            u=fila.top().ss;
            dist_u = fila.top().ff;
            fila.pop();

            if(dist_u<dist[u]) break;
        }

        if(dist_u>=dist[u]) break;

        dist[u] = dist_u;

        for(tiii edge: adj[u]){
            int v, lenght;
            tie(v, lenght, ignore) = edge;

            if(dist[u] + (ll)lenght < dist[v]){
                fila.emplace(dist[u] + (ll)lenght, v);
            }
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

        adj[a].EB(b, dist, ki);
        adj[b].EB(a, dist, ki);
    }

    dijkstra(1);
    cout << (dist[n]!=INF? dist[n]: -1) << endl;

    return 0;
}
