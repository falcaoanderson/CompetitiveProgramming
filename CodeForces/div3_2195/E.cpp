/*
15/02/26 

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

void dfs(int u, vector<vector<int>>& adj, vector<int>& memo){
    if(adj[u].empty()){
        memo[u] = 1;
        return;
    }

    memo[u] = 3;
    for(int v: adj[u]){
        dfs(v, adj, memo);
        memo[u] += memo[v];
        memo[u] %= MOD;
    }
}

void dfs2(int u, vector<vector<int>>& adj, vector<int>& memo){
    for(int v: adj[u]){
        memo[v] += memo[u];
        memo[v] %= MOD;
        dfs2(v, adj, memo);
    }
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for(int i=1; i<=n; i++){
        int l, r;
        cin >> l >> r;
        
        if(l !=0 || r !=0){
            adj[i].PB(l);
            adj[i].PB(r);
        }
    }

    vector<int> memo(n+1);
    dfs(1, adj, memo);
    dfs2(1, adj, memo);

    for(int i=1; i<=n; i++){
        cout << memo[i] << " ";
    }
    cout << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
