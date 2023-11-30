/*
30/11/23 
Problem: Download Speed - CSES Problem Set
Complexity: O(m^2*logC)
*/

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
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const  ll LINF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (5e2) + 5;

int n;
vector<int> adj[MAXN];
ll flow[MAXN][MAXN];
bool visited[MAXN];

ll lower_bound_flow;
ll dfs(int u, ll min_edge){
    visited[u] = 1;
    if(u==n) return min_edge;
    
    for(int v: adj[u]){
        if(!visited[v] && flow[u][v]>lower_bound_flow){
            int w = dfs(v, min(min_edge, flow[u][v]));

            if(w > 0LL){
                flow[u][v] -= w;
                flow[v][u] += w;

                return w;
            }
        }
    }

    return 0LL;
}

ll max_flow(){
    ll total_flow = 0;
    
    lower_bound_flow = LINF;

    while(true){
        memset(visited, 0, sizeof(visited));
        ll w = dfs(1, LINF);

        if(w==0LL && lower_bound_flow==0LL) break;
        if(w==0LL) lower_bound_flow /= 2LL;

        total_flow += w;
    }

    return total_flow;
}

int main(){
    fast_io;
    
    int m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].PB(b);
        adj[b].PB(a);

        flow[a][b] += c;
    }


    cout << max_flow() << endl;

    return 0;
}
