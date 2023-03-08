// 10/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, ll> pii;
typedef pair<ll, int> pli;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 10;
const int MOD = (1e9) + 7;

int n, m, rotas[MAXN], minf[MAXN], maxf[MAXN], grau[MAXN];
ll dist[MAXN];
vector<pii> adj[MAXN], new_adj[MAXN];

void dijkstra(){
    priority_queue<pli, vector<pli>, greater<pli> > fila;
    for(int i=1; i<=n; i++) dist[i] = INF;
    dist[1] = 0;
    fila.push({0, 1});

    while(!fila.empty()){
        int u = fila.top().second; ll d = fila.top().first; fila.pop();

        if(dist[u]!=d) continue;

        for(pii edge: adj[u]){
            int v = edge.first;
            d = dist[u] + edge.second;

            // se faz parte de um caminho minimo eu mantenho no novo grafo
            if(d<=dist[v]) new_adj[u].pb(edge);
            
            if(d<dist[v]){
                dist[v] = d;
                fila.push({d, v});
            }
        }
    }
}

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b; ll c;

        cin >> a >> b >> c;

        adj[a].pb({b, c});
    }

    dijkstra();
    for(int i=1; i<=n; i++) adj[i].clear();
    
    for(int i=1; i<=n; i++){
        for(pii edge: new_adj[i]){
            adj[edge.first].pb({i, edge.second});
            grau[edge.first]++;
        }
    }
    // new_adj  == grafo_menor_caminho // adj == rev_new_adj
     
    queue<int> fila;
    for(int i=1; i<=n; i++){
        if(grau[i]==0) fila.push(i);
        minf[i] = 1e6;
        maxf[i] = -1e6;
        dist[i] = INF;
    }
    dist[1] = 0;
    rotas[1] = 1;
    minf[1] = maxf[1] = 0;

    while(!fila.empty()){
        int u = fila.front(); fila.pop();

        for(pii edge: adj[u]){
            int v = edge.first;     
            ll new_dist = dist[v] + edge.second;

            if(new_dist==dist[u]){
                rotas[u] = (rotas[u] + rotas[v])%MOD;
                minf[u] = min(minf[u], minf[v]+1);
                maxf[u] = max(maxf[u], maxf[v]+1);
            }
            else if(new_dist<dist[u]){
                dist[u] = new_dist;
                rotas[u] = rotas[v];
                minf[u] = minf[v] + 1;
                maxf[u] = maxf[v] + 1;
            }
        }   


        for(pii edge: new_adj[u]){
            grau[edge.first]--;
            if(grau[edge.first]==0) fila.push(edge.first);
        }
    }
    
    cout << dist[n] << " " << rotas[n] << " " << minf[n] << " " << maxf[n] << endl;
    
    return 0;
}
