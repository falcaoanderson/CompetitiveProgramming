// 28/05/23 // dfs // O(n+m) -> O(n)
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

const int MAXN = (2e5) + 5;

int n, dist[MAXN], id_dist[MAXN];
vector<int> graph[MAXN];

void dfs(int u, int last){
    dist[u] = 0;
    id_dist[u] = u;

    for(int v: graph[u]){
        if(v==last) continue;

        dfs(v, u);

        if(dist[u] < dist[v] + 1){
            dist[u] = dist[v] + 1;
            id_dist[u] = id_dist[v];
        }
    }
}

int main(){
    fast_io;

    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        graph[a].PB(b);
        graph[b].PB(a);
    }

    dfs(1, 0);
    
    int u = id_dist[1];

    dfs(u, 0);

    cout << dist[u] << endl;

    return 0;
}
