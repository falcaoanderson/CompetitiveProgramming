/*
08/05/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int dfs_a(int u, int p, vector<vector<int>> &adj, vector<int> &qnt, vector<bool> &marked){
    qnt[u] = (SZ(adj[u]) == 1);
    int ans = 0;

    for(int v: adj[u]){
        if(v == p) continue;

        ans += dfs_a(v, u, adj, qnt, marked);

        qnt[u] += qnt[v];
    }

    if(p >= 0 && (qnt[u] & 1)){
        marked[u] = 1;
        ans++;
    }

    return ans;
}

int dfs_b(int u, int p, vector<vector<int>> &adj, vector<bool> &marked){
    int crr = 0;
    for(int v: adj[u]){
        if(v == p) continue;
        
        crr = min(crr, dfs_b(v, u, adj, marked));
    }
    
    if(p != -1) crr += (marked[u]? -1: 1);

    return crr;
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    vector<int> qnt(n);
    vector<bool> marked(n);
    
    int n_leaf = 0, root = -1;
    for(int i=0; i<n; i++){
        if(SZ(adj[i]) == 1){
            n_leaf++;
        }
        else{
            root = i;
        }
    }
    
    assert(root != -1);

    int ans = dfs_a(root, -1, adj, qnt, marked);
    if(n_leaf & 1){
        ans += dfs_b(root, -1, adj, marked);
    }

    cout << ans << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
