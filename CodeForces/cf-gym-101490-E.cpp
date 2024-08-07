/*
06/02/24 
Problem: 
Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef pair< ll, int> pli;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e4) + 5;
const int MOD  = (1e9) + 7;

int n, m;
ll dist[MAXN];
vector<pii> adj[MAXN];
priority_queue<pli, vector<pli>, greater<pli> > pqueue;

void dijikstra(ll max_w){
    for(int i=1; i<=n; i++) dist[i] = LINF;

    pqueue.emplace(0, 1);

    while(!pqueue.empty()){
        int u = pqueue.top().SS;
        ll  d = pqueue.top().FF;
        pqueue.pop();

        if(d>=dist[u]) continue;
        dist[u] = d;

        for(pii e: adj[u]){
            int v = e.FF;
            ll  w = e.SS;

            if(w>max_w) continue;

            if(dist[u]+w < dist[v]){
                pqueue.emplace(dist[u] + w, v);
            }
        }
    }
}

int main(){
    fast_io;

    ll p;
    cin >> n >> m >> p;

    for(int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].EB(b, w);
        adj[b].EB(a, w);
    }

    dijikstra(1e9);
    ll bound = dist[n] * (100LL + p);

    int l=1, r=1e9, mid, resp;

    while(l<=r){
        mid = (l+r)/2;
        dijikstra(mid);

        if(dist[n]!=LINF && dist[n]*100LL <= bound){
            resp = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    cout << resp << endl;

    return 0;
}
