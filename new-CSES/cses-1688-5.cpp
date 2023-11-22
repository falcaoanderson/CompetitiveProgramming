/* naive1 - não passa (TLE)
Date: 22/11/23 
Problem: LCA
Complexity: <O(n), O(n)>
*/
 
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
 
#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back

const int MAXN = (2e5) + 5;
 
int n;
vector<int> adj[MAXN];
int level[MAXN], pai[MAXN];

void dfs(int u){
    for(int v: adj[u]){
        if(v!=pai[u]){
            pai[v] = u;
            level[v] = level[u] + 1;

            dfs(v);
        }
    } 
}

int lca(int u, int v){
    if(level[u]<level[v]) swap(u, v);

    while(level[u]>level[v]){
        u = pai[u];
    }

    while(u!=v){
        u = pai[u];
        v = pai[v];
    }

    return u;
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
    dfs(1);

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << endl;
    }
 
    return 0;
}