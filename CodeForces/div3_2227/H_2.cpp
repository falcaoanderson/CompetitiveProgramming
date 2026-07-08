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

    priority_queue<pii, vector<pii>, greater<pii>> fila;
    vector<vector<int>> dist(n);
    vector<bool> visited(n);
    vector<int> count(n);

    for(int i=0; i<n; i++){
        if(SZ(adj[i]) == 1){
            fila.push({0, i});
            dist[i].PB(0);
        }
    }

    ll ans = 0;
    while(!fila.empty()){
        int u = fila.top().SS;
        fila.pop();

        visited[u] = 1;
        // cout << "u: " << u << endl;
        // cout << "dist[u]: ";
        // for(int x: dist[u]) cout << x << " ";
        // cout << endl;

        int max_dist = -1;
        if((SZ(dist[u]) & 1)){
            while(!dist[u].empty()){
                max_dist = max(max_dist, dist[u].back());
                ans += (ll)dist[u].back();
                dist[u].pop_back();
            }
            ans -= (ll)max_dist;
        }
        else{
            while(!dist[u].empty()){
                ans += (ll)dist[u].back();
                dist[u].pop_back();
            }
        }
        
        for(int v: adj[u]){
            if(visited[v] == 1) continue;
            
            count[v]++;
            if(max_dist != -1){
                dist[v].PB(max_dist + 1);
            }

            if(SZ(adj[v]) == count[v] + 1){
                fila.push({max_dist + 1, v});
            }
        }
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