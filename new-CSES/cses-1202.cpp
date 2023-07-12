// 12/07/23 //
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
const int iINF = 0x3f3f3f3f;
const int MAXN = (1e5) + 5;
const ll  MOD  = (1e9) + 7;
 
int n, m;
int min_flights[MAXN], max_flights[MAXN];
ll dist[MAXN], paths[MAXN];
vector<pii> graph[MAXN], min_graph[MAXN];
int indegree[MAXN];
vector<int> inv_min_graph[MAXN];

void dijkstra(int start){
    priority_queue< pli, vector<pli>, greater<pli> > pqueue;
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    pqueue.emplace(0LL, start);
 
    while(!pqueue.empty()){
        int u=0; 
        ll d=0;
 
        while(!pqueue.empty()){
            u = pqueue.top().ss;
            d = pqueue.top().ff;
            pqueue.pop();
 
            if(dist[u]>d) break;
            u=0;
        }
        if(u==0) break;
 
        dist[u] = d;
 
        for(pii edge: graph[u]){
            int v = edge.ff;
            ll  d = edge.ss;
 
            if(dist[v]>dist[u] + d){
                pqueue.emplace(dist[u]+d, v);
            }
        }
    }
}

void build_min_graph(int start){
    queue<int> fila;
    vector<bool> visitado(n+1);

    fila.push(start);

    while(!fila.empty()){
        int u = fila.front(); fila.pop();

        if(visitado[u]) continue;

        visitado[u] = 1;

        for(pii edge: graph[u]){
            int v = edge.ff;
            ll  d = edge.ss;

            if(dist[u]+d == dist[v]){
                min_graph[u].EB(v, d);
                indegree[v]++;
                inv_min_graph[v].PB(u);

                if(!visitado[v]) fila.push(v);
            }
        }
    }
}

void number_of_shortest_path(int start){
    queue<int> fila;
    fila.push(start);

    for(int i=1; i<=n; i++){
        max_flights[i] = -iINF;
        min_flights[i] = iINF;
    }

    paths[start] = 1;
    max_flights[start] = min_flights[start] = 0;

    while(!fila.empty()){
        int u = fila.front(); fila.pop();

        for(int v: inv_min_graph[u]){
            paths[u] = (paths[u] + paths[v])%MOD;

            max_flights[u] = max(max_flights[u], max_flights[v] + 1);
            min_flights[u] = min(min_flights[u], min_flights[v] + 1);
        }

        for(pii edge: min_graph[u]){
            int v = edge.ff;

            indegree[v]--;
            if(indegree[v]==0) fila.push(v);
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
    build_min_graph(1);
    number_of_shortest_path(1);

    cout << dist[n] << " " << paths[n] << " " << min_flights[n] << " " << max_flights[n] << endl; 
 
    return 0;
}