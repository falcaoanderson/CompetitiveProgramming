/*
23/08/25 

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
const int MAXN = (1e6) + 5;
const int MOD  = (1e9) + 7;

vector<int> adj[MAXN];
int dist[MAXN], ways[MAXN], ways_rev[MAXN];

int main(){
    fast_io;

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].PB(v);
        adj[v].PB(u);
    }

    // reverse 
    queue<int> fila;
    fila.push(t);
    dist[t] = 1;
    ways_rev[t] = 1;

    while(!fila.empty()){
        int u = fila.front(); fila.pop();

        for(int v: adj[u]){
            if(dist[v]==0){
                dist[v] = dist[u]+1;
                fila.push(v);
            }
            if(dist[v]==dist[u]+1){
                ways_rev[v] += ways_rev[u];
                ways_rev[v] %= MOD;
            }   
        }
    }

    if(dist[s]==0){
        cout << 0 << endl;
        return 0;
    }

    // usual
    int resp = 0;
    fila.push(s);
    ways[s] = 1;
    vector<bool> visited(n+1);

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        if(visited[u]) continue;
        visited[u] = 1;

        for(int v: adj[u]){
            if(dist[v]==dist[u]-1){
                ways[v]+=ways[u];
                ways[v]%=MOD;
            }
            if(dist[v]==dist[u]){
                resp += ((ll)(ways[u]) * (ll)(ways_rev[v])) % (ll)(MOD);
                resp %= MOD;
            }
            if(!visited[v]){
                fila.push(v);
            }
        }
    }

    cout << resp << endl;

    return 0;
}
