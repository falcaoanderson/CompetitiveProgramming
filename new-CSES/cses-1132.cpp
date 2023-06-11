// 11/06/23 // dp in tree // O(n+m)
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
 
int n, dist_up[MAXN];
int dist_down1[MAXN], dist_down2[MAXN], id1[MAXN], id2[MAXN];
 
vector<int> graph[MAXN];
 
void dfs_down(int u, int last){
    for(int v: graph[u]){
        if(v==last) continue;
 
        dfs_down(v, u);
 
        if(dist_down1[u]<dist_down1[v]+1){
            dist_down2[u] = dist_down1[u];
            id2[u] = id1[u];
 
            dist_down1[u] = dist_down1[v]+1;
            id1[u] = v;
        }
        else if(dist_down2[u]<dist_down1[v]+1){
            dist_down2[u] = dist_down1[v]+1;
            id2[u] = v;
        }
    }
}
 
void dfs_up(int u, int last){
    for(int v: graph[u]){
        if(v==last) continue;
 
        dist_up[v] = 1 + max(dist_up[u], (id1[u]!=v? dist_down1[u]: dist_down2[u]) );
 
        dfs_up(v, u);
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
 
    dfs_down(1, 0);
    dfs_up(1, 0);
 
    for(int i=1; i<=n; i++){
        cout << max(dist_down1[i], dist_up[i]) << " ";
    }
    cout << endl;
 
    return 0;
}