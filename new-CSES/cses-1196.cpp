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
typedef pair< ll, int> pli;
typedef tuple<int, int, int> tiii;
 
const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;
 
int n, k;
ll dist[MAXN][15];
vector<pii> adj[MAXN];
 
void dijkstra(int start){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++) dist[i][j] = INF;
    }
    dist[start][1] = 0;
 
    priority_queue< pli, vector<pli>, greater<pli> > pq;
    pq.emplace(0, start);
    
    while(!pq.empty()){
        ll dist_u; int u;
        tie(dist_u, u) = pq.top();
 
        pq.pop();

        if(dist_u > dist[u][k]) continue;
 
        for(pii edge: adj[u]){
            int v = edge.ff;
            ll  w = edge.ss;
 
            for(int i=1; i<=k; i++){
                if(dist_u+w < dist[v][i]){
                    for(int j=k; j>=i+1; j--){
                        dist[v][j] = dist[v][j-1];
                    }

                    dist[v][i] = dist_u+w;
                    pq.emplace(dist[v][i], v);
                    break;
                }
            }
        }
    }
}
 
int main(){
    fast_io;
 
    int m;
    cin >> n >> m >> k;
 
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
 
        adj[a].EB(b, c);
    }
 
    dijkstra(1);
 
    for(int i=1; i<=k; i++) cout << dist[n][i] << " ";
    cout << endl;
 
    return 0;
}