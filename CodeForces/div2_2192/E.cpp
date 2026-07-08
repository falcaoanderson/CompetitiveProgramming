/*
16/03/26 

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

void dfs(int u, vector<vector<int>>& adj, vector<int>& a, vector<int>& b, vector<bool>& ans){
    while(!adj[u].empty()){
        int e = adj[u].back();
        adj[u].pop_back();

        if(a[e] == -1) continue;
        
        int v;
        if(u == a[e]){ // a --> b
            ans[e] = 0;
            v = b[e];
        }
        else{ // b -- > a
            ans[e] = 1;
            v = a[e];
        }
        a[e] = b[e] = -1;
        
        dfs(v, adj, a, b, ans);
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            adj[a[i]].PB(i);
            adj[b[i]].PB(i);
        }
    }

    bool flag = 1;
    for(int i=1; i<=n && flag; i++){
        flag = flag && ((SZ(adj[i]) % 2) == 0);
    }
    if(!flag){
        cout << -1 << endl;
        return;
    }

    vector<bool> ans(n);
    for(int i=1; i<=n; i++){
        if(!adj[i].empty()) dfs(i, adj, a, b, ans);
    }
    
    int qnt = 0;
    for(int i=0; i<n; i++){
        if(ans[i]) qnt++;
    }
    cout << qnt << endl;
    for(int i=0; i<n; i++){
        if(ans[i]) cout << i+1 << " ";
    }
    cout << endl;
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
