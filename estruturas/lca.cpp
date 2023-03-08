// 21/11/20 // xx:xx PM //
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long
 
typedef pair<int, int> pii;
 
const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;
const int MOD  = (1e9) + 7;
 
int n, q;
vector<int> adj[MAXN];
int level[MAXN], anc[MAXN][20]; 
 
void dfs(int u, int pa){
    for(int v: adj[u]){
        if(v==pa) continue;
 
        level[v] = level[u] + 1;
        dfs(v, u);
    }
}
 
int lca(int u, int v){
    if(level[u]>level[v]) swap(u, v); // faz level[u]<=level[v]
 
    for(int i=18; i>=0; i--)           // faz level[u]==level[v]
        if(anc[v][i]!=0 && level[anc[v][i]]>=level[u])
            v = anc[v][i];
 
    if(u==v) return u;
 
    for(int i=18; i>=0; i--){  // subo o maximo der sem chegar  no LCA
        if(anc[u][i]!=0 && anc[u][i]!=anc[v][i]){
            u = anc[u][i];
            v = anc[v][i];
        }
    }
 
    return anc[u][0]; // entao o proximo ancestral eh o LCA
}
 
int main(){
    fast_io;
 
    cin >> n >> q;
    for(int i=2; i<=n; i++){
        int a;
        cin >> a;
 
        anc[i][0] = a;
        adj[a].pb(i);
        adj[i].pb(a);
    }
 
    dfs(1, 0);
 
    for(int j=1; j<19; j++)
        for(int i=2; i<=n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
 
    while(q--){
        int a, b;
        cin >> a >> b;
 
        cout << lca(a, b) << endl;
    }
 
    return 0;
}