// 24/08/24 // Virtual
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

typedef tuple<ll, ll, ll> tiii;
typedef pair<ll, int> pii; 

int n, start_time;
ll dist[MAXN];
vector<tiii> adj[MAXN];

void dij(){
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.emplace(start_time, 1);

    for(int i=1; i<=n; i++) dist[i] = LINF;

    while(!pq.empty()){
        int u = pq.top().second;
        ll u_time = pq.top().first;
        pq.pop();

        if(u_time >= dist[u]){
            continue;
        }

        dist[u] = u_time;

        for(tiii edge: adj[u]){
            ll v, op, cl;
            tie(v, op, cl) = edge;

            ll d = u_time + ( (u_time%(op+cl)) < op ? 0LL: op+cl - (u_time%(op+cl)) );

            if(d<dist[v]){
                pq.emplace(d, v);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int m;
    cin >> n >> m >> start_time;

    for(int i=0; i<m; i++){
        ll a, b, op, cl;
        cin >> a >> b >> op >> cl;

        adj[a].emplace_back(b, op, cl);
        adj[b].emplace_back(a, op, cl);
    }    

    dij();

    cout << dist[n] << endl;

    return 0;
}