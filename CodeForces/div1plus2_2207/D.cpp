/*
10/03/26 

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
const int MAXN = (5e5) + 5;
const int MOD  = (1e9) + 7;

int d1[MAXN], d2[MAXN];
vector<vector<int>> adj;

void dfs(int u, int p, int k){
    d1[u] = d2[u] = INF;

    if(adj[u].size() == 1){
        d1[u] = d2[u] = 0;
        return;
    }

    for(int v: adj[u]){
        if(v == p) continue;

        dfs(v, u, k);

        if(d1[v] + 1 < d1[u]){
            d2[u] = d1[u];
            d1[u] = d1[v] + 1;
        }
        else if(d1[v] + 1 < d2[u]){
            d2[u] = d1[v] + 1;
        }
    }

    if(d1[u] + d2[u] <= k+1){
        d1[u] = d2[u] = 0;
    }
}

void solve(){
    int n, k, st;
    cin >> n >> k >> st;

    adj.assign(n+1, vector<int>());

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }    

    dfs(st, 0, k);

    cout << (d1[st] == 0? "YES": "NO") << endl;
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
