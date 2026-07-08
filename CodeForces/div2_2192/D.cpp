/*
21/02/26 

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

vector<vector<int>> adj; 
vector<ll> val, w, cost, ucost;
vector<ll> dist, sdist, nd, nsd;

void dfs(int u, int p){
    w[u] += val[u];
    cost[u] = 0;

    for(int v: adj[u]){
        if(v == p) continue;

        dfs(v, u);
        
        if(dist[v] + 1 > dist[u]){
            sdist[u] = dist[u];
            nsd[u] = nd[u];

            dist[u] = dist[v] + 1;
            nd[u] = v;
        }
        else if(dist[v] + 1 > sdist[u]){
            sdist[u] = dist[v] + 1;
            nsd[u] = v;
        }

        w[u] += w[v];
        cost[u] += cost[v] + w[v]; 
    }
    ucost[u] = cost[u];

    for(int v: adj[u]){
        if(v == p) continue;

        ucost[u] = max(ucost[u], cost[u] - cost[v] + ucost[v]);

        if(nd[u]!=0 && v != nd[u]){
            ucost[u] = max(ucost[u], cost[u] + w[v] * dist[u]);
        }
        else if(nsd[u]!=0 && v != nsd[u]){
            ucost[u] = max(ucost[u], cost[u] + w[v] * sdist[u]);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    
    val.assign(n, 0);
    adj.assign(n, vector<int>(0));
    w.assign(n, 0);
    cost.assign(n, 0);
    ucost.assign(n, 0);
    dist.assign(n, 0);
    sdist.assign(n, 0);
    nd.assign(n, 0);
    nsd.assign(n, 0);

    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].PB(b-1);
        adj[b-1].PB(a-1);
    }

    dfs(0, 0);

    for(ll x: ucost) cout << x << " ";
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
