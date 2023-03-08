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
 
const int MAXN = (1e5) + 10;
 
int n, q, color[MAXN];
vector<int> adj[MAXN];
int level[MAXN], anc[MAXN][20], pre_tree[MAXN], bit[MAXN][55], pos[MAXN], qnt[MAXN], ii=0; 
 
void dfs(int u, int pa){
    pre_tree[++ii] = u;
    pos[u] = ii;

    qnt[u] = 1;
    for(int v: adj[u]){
        if(v==pa) continue;
        
        anc[v][0] = u;
        level[v] = level[u] + 1;
        
        dfs(v, u);

        qnt[u] += qnt[v];
    }
}

void update(int cor, int i, int val){
    while(i<=n){
        bit[i][cor] += val;
        i += (i&-i);
    }
}
int query(int cor, int i){
    int sum = 0;
    while(i>0){
        sum += bit[i][cor];
        i -= (i&-i);
    }
    return sum;
}

void pre_processing(){
    dfs(1, 0);
    for(int j=1; j<19; j++)
        for(int i=2; i<=n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
    
    for(int i=1; i<=n; i++){
        int u = pre_tree[i];
        update(color[u], pos[u], 1);
        update(color[u], pos[u]+qnt[u], -1);
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
 
    cin >> n;
    for(int i=1; i<=n; i++) cin >> color[i];
    for(int i=1; i<=n-1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].pb(v); adj[v].pb(u);
    }
 
    pre_processing();
    
    cin >> q;
    while(q--){
        int op;
        cin >> op;

        if(op==1){ // update
            int u, x;
            cin >> u >> x;

            update(color[u], pos[u], -1);
            update(color[u], pos[u]+qnt[u], 1);

            color[u] = x;
            update(color[u], pos[u], 1);
            update(color[u], pos[u]+qnt[u], -1);
        }
        else{ // query
            int u, v;
            cin >> u >> v;

            int x = anc[lca(u, v)][0];
            int resp = 0;

            for(int k=1; k<=50; k++)
                resp += min(query(k, pos[u]) + query(k, pos[v]) -2 * query(k, pos[x]), 1);
            
            cout << resp << endl;
        }
        
    }
    
 
    return 0;
}