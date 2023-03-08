// 04/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<ll, ll> pii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m;
ll dist[MAXN];
vector<pii> adj[MAXN];

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii> > fila;
    for(int i=1; i<=n; i++) dist[i] = INF;

    fila.push({0, 1});
    dist[1] = 0;

    while(!fila.empty()){
        int u = fila.top().second; 
        ll  d = fila.top().first;
        fila.pop();

        if(d!=dist[u]) continue;

        for(pii temp: adj[u]){
            int v = temp.first;
            ll new_dist = dist[u] + temp.second;

            if(dist[v]>new_dist){
                dist[v] = new_dist;
 
                fila.push({dist[v], v});
            }
        }
    }
}

int main(){
    fast_io;
    
    cin >> n >> m;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].pb({b, c});
    }

    dijkstra();

    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}
