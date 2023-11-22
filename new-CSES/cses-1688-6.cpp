/* naive2 - não passa (TLE)
Date: 22/11/23 
Problem: LCA with euler tour technique and sparse table
Complexity: <O(n^2), O(1)>
*/
 
#include <iostream>
#include <vector>
#include <cstring>
 
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
 
const int MAXN = (1e3) + 5;
 
int n;
vector<int> adj[MAXN];
int level[MAXN], pai[MAXN];
int memo[MAXN][MAXN];

void dfs(int u, int last){
    for(int v: adj[u]){
        if(v!=last){
            pai[v] = u;
            level[v] = level[u] + 1;

            dfs(v, u);
        }
    } 
}

int lca(int u, int v){
    if(memo[u][v]!=-1) return memo[u][v];

    if(u==v) return memo[u][v] = u;

    if(level[u]<level[v]) swap(u, v);

    return memo[u][v] = lca(pai[u], v);
}

int main(){
    fast_io;
 
    int q;
    cin >> n >> q;
 
    for(int b=2; b<=n; b++){
        int a;
        cin >> a;
 
        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    pai[1] = 1;
    dfs(1, 0);

    memset(memo, -1, sizeof(memo));

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << endl;
    }
 
    return 0;
}