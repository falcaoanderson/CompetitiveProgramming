// 06/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, ll> pii;
typedef pair<ll, int> plli;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m, k, cont[MAXN];
vector<pii> adj[MAXN];
ll dist[MAXN];

void dijkstra(){
    priority_queue<plli, vector<plli>, greater<plli>> fila;
    for(int i=1; i<=n; i++) dist[i] = INF;

    dist[1] = 0;
    fila.push({0, 1});

    while(!fila.empty() && cont[n]<k){
        int u = fila.top().second;
        ll d = fila.top().first;
        fila.pop();

        cont[u]++;
        if(u==n) cout << d << " ";

        if(cont[u]>k) continue;

        for(auto temp: adj[u]){
            int v = temp.first;
            ll new_dist = d + temp.second;

            fila.push({new_dist, v});
        }
    }
}

int main(){
    fast_io;
    
    cin >> n >> m >> k;

    for(int i=0; i<m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;

        adj[a].pb({b, c});
    }

    dijkstra();
    cout << endl;
    
    return 0;
}
