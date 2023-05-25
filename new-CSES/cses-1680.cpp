// 25/05/23 // dfs // O(n+m)
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
const int MOD  = (1e9) + 7;

int n, m;
vector<int> graph[MAXN];

bool visited[MAXN];
int dist[MAXN], path[MAXN];

void dfs(int u){
    visited[u] = 1;
    
    dist[u] = (u==n? 0: -INF);

    for(int v: graph[u]){
        if(!visited[v]) dfs(v);

        if(dist[v]!=-INF && dist[u] < dist[v]+1){
            dist[u] = dist[v]+1;
            path[u] = v;
        }
    }
}   


int main(){
    fast_io;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        graph[a].PB(b);
    }

    dfs(1);

    if(dist[1]==-INF){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << dist[1]+1 << endl;
        
        int u=1;
        while(u!=n){
            cout << u << " ";
            u = path[u];
        }
        cout << u << endl;
    }

    return 0;
}
