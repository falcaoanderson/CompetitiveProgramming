// 20/05/23 // dijkstra 
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

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ll long long
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef tuple<int, int, int> tiii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;

int n, m;
ll dist[MAXN];
vector<pii> graph[MAXN];

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

        for(pii vd: graph[u]){
            int v      = vd.ff;
            ll  lenght = vd.ss;

            if(dist[u] + lenght < dist[v]){
                fila.emplace(dist[u]+lenght, v);
            }
        }
    }
}

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].EB(b, c);
    }

    dijkstra(1);

    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}
