// 06/11/20 // 7:10 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, ll> pii;
typedef tuple<ll, int, int> plii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m;
ll dist[MAXN][2];       // [i][0] nao usei o desconto / [i][1] ja usei o desconto 
bool visitado[MAXN][2];
vector<pii> adj[MAXN];

void dijkstra(){
    priority_queue<plii, vector<plii>, greater<plii>> fila;
    for(int i=1; i<=n; i++) dist[i][0] = dist[i][1] = INF;

    dist[1][0] = dist[1][1]= 0;
    fila.push({0, 1, 0}); // {dist, vertice, flag}

    while(!fila.empty()){
        int u, flag; ll d;

        tie(d, u, flag) = fila.top(); fila.pop();

        if(visitado[u][flag]) continue;
        visitado[u][flag] = 1;

        for(pii edge: adj[u]){
            int v = edge.first;
            ll new_dist;
            if(flag==1){
                new_dist = dist[u][1] + edge.second;
                
                if(new_dist<dist[v][1]){
                    dist[v][1] = new_dist;
                    fila.push({new_dist, v, 1});
                }
            }
            else{
                // nao usando desconto
                new_dist = dist[u][0] + edge.second;
                
                if(new_dist<dist[v][0]){
                    dist[v][0] = new_dist;
                    fila.push({new_dist, v, 0});
                }

                // usando desconto
                new_dist = dist[u][0] + edge.second/2;

                if(new_dist<dist[v][1]){
                    dist[v][1] = new_dist;
                    fila.push({new_dist, v, 1});
                }
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

    cout << dist[n][1] << endl;

    return 0;
}
