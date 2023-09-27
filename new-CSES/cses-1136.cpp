// 26/09/23 // 
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
 
const int MAXN = (2e5) + 5;
const int LOGMAXN = 17;
 
int n;
int level[MAXN], ancestor[MAXN][LOGMAXN+5];
vector<int> adj[MAXN];
 
void dfs(int u, int last){
    for(int v: adj[u]){
        if(v==last) continue;
 
        ancestor[v][0] = u;
        level[v] = level[u]+1;
 
        dfs(v, u);      
    }
}
 
void build_ancestor(){
    for(int k=1; k<=LOGMAXN; k++){
        for(int i=1; i<=n; i++){
            ancestor[i][k] = ancestor[ancestor[i][k-1]][k-1];
        }
    }
}
 
int lca(int u, int v){
    if(level[u]<level[v]) swap(u, v);
 
    for(int k=LOGMAXN; k>=0; k--){
        if(ancestor[u][k]!=0 && level[ancestor[u][k]]>=level[v]){
            u = ancestor[u][k];
        }
    }
 
    if(u==v) return u;
 
    for(int k=LOGMAXN; k>=0; k--){
        if(ancestor[u][k]!=ancestor[v][k] && ancestor[u][k+1]==ancestor[v][k+1]){
            u = ancestor[u][k];
            v = ancestor[v][k];
        }
    }
    
    return ancestor[u][0];
}

int val[MAXN], aux[MAXN];
void dfs_calc(int u, int last){
    for(int v: adj[u]){
        if(v==last) continue;

        dfs_calc(v, u);
        val[u] += val[v];
    }
}
 
int main(){
    fast_io;
 
    int q;
    cin >> n >> q;
 
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }
 
    dfs(1, 0);
    build_ancestor();
 
    while(q--){
        int u, v;
        cin >> u >> v;
 
        int w = lca(u, v);

        val[u]++;
        val[v]++;
        val[w]-=2;
        aux[w]++;
    }
    
    dfs_calc(1, 0);

    for(int i=1; i<=n; i++) cout << val[i] + aux[i] << " ";
    cout << endl;

    return 0;
}