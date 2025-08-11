/*
09/08/25 

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
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int n, val[MAXN];
int dist[MAXN];
bool check[MAXN];
map<int, int> last;
vector<int> adj[MAXN];

void fill_dist(int ini) {
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    for(int i=0; i<n; i++) dist[i] = INF;
    dist[ini] = 0;
    fila.push({0, 0});

    while (!fila.empty()) {
        int u = fila.top().SS, d=fila.top().FF;
        fila.pop();

        if(dist[u]<d) continue;
        
        for (auto v: adj[u]) {
            int w = val[u]!=val[v];

            if (dist[v]>dist[u]+w) {
                dist[v] = dist[u]+w;
                fila.push({dist[v], v});
            }
        }
    }
}

int main() {
    fast_io;

    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> val[i];
    
    for (int i = 0; i < n; i++) {
        if (last.find(val[i])!=last.end()){
            adj[last[val[i]]].PB(i);
        }
        last[val[i]] = i;
    }

    for (int i=1; i<n; i++){
        adj[i-1].PB(i);
    }
    fill_dist(0);

    cout << dist[n-1]+1 << '\n';

    return 0;
}