/*
01/03/24 
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
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e4) + 5;
const int MAXM = (1e5) + 5;
const int MOD  = (1e9) + 7;

int in[MAXN], low[MAXN], tt=0;
int color[MAXN], qc=0;
vector<int> adj[MAXN], new_adj[MAXN];

void dfs1(int u, int p){
    in[u] = low[u] = (++tt);

    for(int v: adj[u]){
        if(v==p) continue;

        if(in[v]==0){ //son
            dfs1(v, u);

            low[u] = min(low[u], low[v]);
            
            if(low[v]>in[u]){
                new_adj[u].PB(v);
                new_adj[v].PB(u);
            }   
        }
        else if(in[v]<in[u]){ //backedge
            low[u] = min(low[u], in[v]);
        }
    }
}

void dfs2(int u){
    for(int v: new_adj[u]){
        if(color[v]==0){
            color[v] = color[u];
            dfs2(v);
        }
    }
}

int main(){
    fast_io;

    int n, m, q;

    while(true){
        cin >> n >> m >> q;

        if(n==0) break;

        tt = qc = 0;
        memset(color, 0, sizeof(color));
        memset(in, 0, sizeof(in));
        memset(low, 0, sizeof(low));
        for(int i=1; i<=n; i++){
            adj[i].clear();
            new_adj[i].clear();
        }

        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;

            adj[a].PB(b);
            adj[b].PB(a);
        }

        for(int u=1; u<=n; u++){
            if(in[u]==0) dfs1(u, -1);
        }

        for(int u=1; u<=n; u++){
            if(color[u]==0){
                color[u] = (++qc);
                dfs2(u);
            }
        }

        while(q--){
            int a, b;
            cin >> a >> b;

            if(color[a]==color[b]) cout << "Y" << endl;
            else cout << "N" << endl;   
        }
        cout << "-" << endl;
    }

    return 0;
}
