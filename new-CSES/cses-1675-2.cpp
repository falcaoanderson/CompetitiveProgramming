// 11/06/23 // prim algorithm
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
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 5;

int n, m;
vector<pii> graph[MAXN];

ll prim(){
    priority_queue< pii, vector<pii>, greater<pii> > edges;
    
    vector<int> dist(n+1, INF);
    edges.emplace(0, 1);

    while(!edges.empty()){
        int u=0, dist_u=0;

        while(!edges.empty()){
            u = edges.top().ss;
            dist_u = edges.top().ff;

            edges.pop();

            if(dist[u]==INF){
                break;
            }
        }

        if(dist[u]!=INF) break;

        dist[u] = dist_u;

        for(pii edge: graph[u]){
            int v = edge.ff;
            int dist_v = edge.ss;

            if(dist[v]==INF){
                edges.emplace(dist_v, v);
            }
        }
    }

    ll resp = 0LL;
    
    for(int i=1; i<=n; i++){    
        if(dist[i]==INF) return -1LL;

        resp += dist[i];
    }

    return resp;
}

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].EB(b, c);
        graph[b].EB(a, c);
    }

    ll resp = prim();

    if(resp==-1LL){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << resp << endl;
    }

    return 0;
}
