/*
30/01/26

*/
#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[MAXN];
int tt=0, in[MAXN], min_in[MAXN];
bool flag_bridge = 0;
vector<pii> edges;

void dfs(int u, int parent){
    in[u] = min_in[u] = (++tt);

    if(flag_bridge) return;

    for(int v: adj[u]){
        if(v == parent) continue;

        if(in[v] == 0){ // filho
            dfs(v, u);
            min_in[u] = min(min_in[u], min_in[v]);

            edges.PB({u, v});

            if(min_in[v] > in[u]){ // bridge
                flag_bridge = 1;
                return;
            }
        }
        else if(in[v] < in[u]){ // back-edge
            edges.PB({u, v});
            min_in[u] = min(min_in[u], in[v]);
        }
    }
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    dfs(1, 0);

    if(flag_bridge){
        cout << 0 << endl;
    }
    else{
        for(pii p: edges){
            cout << p.FF << " " << p.SS << endl;
        }
    }

    return 0;
}