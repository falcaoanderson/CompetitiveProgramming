// 13/08/23 //
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
typedef pair< ll, pii> pli;
typedef tuple<int, int, int> tiii;

const ll  INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;

int n, key[MAXN];
ll resp = INF;
vector<tiii> adj[MAXN];
//ll dist[MAXN];
map<pii, ll> mdist;

void dijkstra(int ini){    
    //for(int i=1; i<=n; i++) dist[i] = INF;

    priority_queue< pli, vector<pli>, greater<pli> > fila;
    fila.push({0LL, {ini, key[ini]}});

    while(!fila.empty()){
        int u=1, crr_key=0;
        ll dist_u=INF;

        while(!fila.empty()){
            u=fila.top().ss.ff;
            crr_key = fila.top().ss.ss;
            dist_u = fila.top().ff;
            fila.pop();
            
            
            if(mdist.find({u, crr_key})==mdist.end() || dist_u<mdist[{u, crr_key}]) break;
        }

        if(mdist.find({u, crr_key})!=mdist.end() && dist_u>=mdist[{u, crr_key}]) break;

        mdist[{u, crr_key}] = dist_u;
        if(u==n) resp = min(resp, dist_u);

        for(tiii edge: adj[u]){
            int v, lenght, f;
            tie(v, lenght, f) = edge;

            if(f!=crr_key) continue;

            if(mdist.find({v, crr_key})==mdist.end() || mdist[{u, crr_key}] + (ll)lenght < mdist[{v, crr_key}]){
                fila.push({mdist[{u, crr_key}] + (ll)lenght, {v, crr_key}});
            }
        }

        if(crr_key!=key[u]){
            if(mdist.find({u, key[u]})==mdist.end() || mdist[{u, crr_key}] < mdist[{u, key[u]}]){
                fila.push({mdist[{u, crr_key}], {u, key[u]}});
            }
        }
    }
}

int main(){
    fast_io;

    int m, k=0;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) cin >> key[i];

    for(int i=0; i<m; i++){
        int a, b, dist, ki;
        cin >> a >> b >> dist >> ki;

        adj[a].EB(b, dist, ki);
        adj[b].EB(a, dist, ki);
    }

    dijkstra(1);

    //for(auto x: mdist){
    //    cout << x.ff.ff << " " << x.ff.ss << ": " << x.ss << endl;
    //}

    cout << (resp!=INF? resp: -1) << endl;

    return 0;
}
