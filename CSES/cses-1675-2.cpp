// 10/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;
typedef tuple<int, int, int> piii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m, dist[MAXN];
vector<pii> adj[MAXN];
bool visitado[MAXN];

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    priority_queue<pii, vector<pii>, greater<pii>> fila;
    for(int i=1; i<=n; i++) dist[i] = INF;
    dist[1] = 0;
    fila.push({dist[1], 1});

    while(!fila.empty()){
        int u = fila.top().second, d = fila.top().first; fila.pop();

        if(visitado[u]) continue;
        visitado[u] = 1;

        for(pii e: adj[u]){
            int v = e.first;
            d = e.second;
            
            if(d<dist[v] && !visitado[v]){
                dist[v] = d;
                fila.push({d, v});
            }
        }
    }
    
    ll resp = 0LL;
    for(int i=1; i<=n; i++){
        if(dist[i]==INF){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        resp += (ll)dist[i];
    }
    cout << resp << endl;

    return 0;
}
