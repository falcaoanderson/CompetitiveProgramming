/*
02/11/25 

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

int n, k, tam[MAXN];
vector<int> adj[MAXN];

ll dfs(int u, int p){
    tam[u] = 1;
    ll resp = 1;

    for(int v: adj[u]){
        if(v==p) continue;

        resp += dfs(v, u);
        tam[u] += tam[v];
    }

    if(tam[u]>=k){
        resp += (ll)(n - tam[u]);
    }
    for(int v: adj[u]){
        if(v==p) continue;

        if(n - tam[v] >= k){
            resp += (ll)tam[v];
        }
    }

    return resp;
}

void solve(){
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        adj[i].clear();
        // tam[i] = 0;
    }

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }

    cout << dfs(1, 0) << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
