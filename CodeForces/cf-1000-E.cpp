/*
14/02/24 
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
const int MAXN = (3e5) + 5;
const int MOD  = (1e9) + 7;

int tin[MAXN], tlower[MAXN], tt=0;
vector<int> adj[MAXN];

void dfs1(int u, int p){
    tin[u] = tlower[u] = (++tt);

    for(int v: adj[u]){
        if(v==p) continue;

        if(tin[v]==0){ //filho
            dfs1(v, u);

            tlower[u] = min(tlower[u], tlower[v]);
        }
        else if(tin[v]<tin[u]){ //back-edge
            tlower[u] = min(tlower[u], tin[v]);
        }
    }
}

vector<int> new_adj[MAXN];
int color[MAXN], qcolor=0;

void dfs2(int u){
    for(int v: adj[u]){
        if(color[v]==0){
            if(tin[v]==tlower[v]){ // ponte
                color[v] = (++qcolor);

                new_adj[color[u]].PB(color[v]);
                new_adj[color[v]].PB(color[u]);
            }
            else{
                color[v] = color[u];
            }

            dfs2(v);
        }
    }
}

pii dfs3(int u, int p){
    pii resp = {0, u};

    for(int v: new_adj[u]){
        if(v==p) continue;

        pii aux = dfs3(v, u); 
        aux.FF++;

        if(aux > resp) resp = aux;
    }

    return resp;
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

    dfs1(1, 0);
    color[1] = (++qcolor);
    dfs2(1);

    /*
    for(int i=1; i<=n; i++) cout << color[i] << " ";
    cout << endl;

    for(int u=1; u<=qcolor; u++){
        cout << u << ": ";
        for(int v: new_adj[u]) cout << v << " ";
        cout << endl;
    }
    */

    cout << dfs3(dfs3(1, 0).SS, 0).FF << endl;

    return 0;
}
