// 19/08/23 //
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
typedef tuple< ll, int, bool> tlib;
typedef tuple<int, int, int> tiii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;

int n;
ll dist[MAXN][5];
vector<pii> adj[MAXN];

void dijkstra(int start){
    for(int i=1; i<=n; i++) dist[i][0] = dist[i][1] = INF;
    dist[start][0] = 0;

    priority_queue< tlib, vector<tlib>, greater<tlib> > pq;
    pq.emplace(0, start, 0);

    while(!pq.empty()){
        ll dist_u; int u; bool op;
        tie(dist_u, u, op) = pq.top();

        pq.pop();

        if((!op && dist_u!=dist[u][0]) || (op && dist_u!=dist[u][1])) continue;

        for(pii edge: adj[u]){
            int v = edge.ff;
            ll  w = edge.ss;

            if(dist[u][op] + w < dist[v][op]){
                dist[v][op] = dist[u][op] + w;

                pq.emplace(dist[v][op], v, op);
            }
            if(!op && dist[u][0]+w/2LL<dist[v][1]){
                dist[v][1] = dist[u][0] + w/2LL;

                pq.emplace(dist[v][1], v, 1);
            }
        }
    }
}

int main(){
    fast_io;

    int m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].EB(b, c);
    }

    dijkstra(1);

    cout << dist[n][1] << endl;

    return 0;
}
