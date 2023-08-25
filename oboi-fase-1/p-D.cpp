// 25/08/23 // solucao completa 100 pts
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef pair< ll, int> pli;
typedef tuple<ll, int, int> tlii;

const ll  INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;

int n, key[MAXN];
int qnt_v=0;
map<pii, int> id_adj;
vector<pii> adj[3*MAXN];
map<pii, ll> dist;

ll dijkstra(){    
    priority_queue< tlii, vector<tlii>, greater<tlii> > fila;
    
    dist[{1, key[1]}] = 0;
    fila.emplace(0LL, 1, key[1]);
    
    ll dist_n = INF;

    while(!fila.empty()){
        int u, k_u; ll dist_u;
        tie(dist_u, u, k_u) = fila.top();
        fila.pop();

        if(dist[{u, k_u}]!=dist_u) continue;

        for(pii edge: adj[ id_adj[{u, k_u}] ]){
            int v = edge.ff;
            ll  d = edge.ss;

            if(dist.find({v, k_u})==dist.end() || dist_u + d < dist[{v, k_u}]){
                dist[{v, k_u}] = dist_u + d;
                fila.emplace(dist_u + d, v, k_u);
            }
        }

        if(dist.find({u, key[u]})==dist.end() || dist_u < dist[{u, key[u]}]){
            dist[{u, key[u]}] = dist_u;
            fila.emplace(dist_u, u, key[u]);
        }

        if(u==n) dist_n = min(dist_n, dist_u);
    }

    return dist_n;
}

int main(){
    fast_io;

    int m, k=0;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) cin >> key[i];

    for(int i=0; i<m; i++){
        int a, b, d, ki;
        cin >> a >> b >> d >> ki;

        if(id_adj.find({a, ki})==id_adj.end()){
            id_adj[{a, ki}] = ++qnt_v;
        }
        if(id_adj.find({b, ki})==id_adj.end()){
            id_adj[{b, ki}] = ++qnt_v;
        }

        adj[id_adj[{a, ki}]].EB(b, d);
        adj[id_adj[{b, ki}]].EB(a, d);
    }

    ll dist_n = dijkstra();

    cout << (dist_n<INF? dist_n: -1) << endl;

    return 0;
}
