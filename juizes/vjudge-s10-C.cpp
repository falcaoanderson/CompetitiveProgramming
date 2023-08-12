// 12/08/23 //
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
typedef tuple<int, int, int> tiii;

const int MAXN = (1e5) + 5;

bool visited[MAXN];
int color[MAXN], qnt_color=0;
vector<int> adj[MAXN], iadj[MAXN];
vector<int> process;

void dfs1(int u){
    visited[u] = 1;

    for(int v: adj[u]){
        if(!visited[v]) dfs1(v);
    }

    process.PB(u);
}

void dfs2(int u){
    color[u] = qnt_color;

    for(int v: iadj[u]){
        if(color[v]==0) dfs2(v);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        visited[i] = 0;
        color[i] = 0;
        qnt_color = 0;

        adj[i].clear();
        iadj[i].clear();
    }
    process.clear();

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].PB(v);
        iadj[v].PB(u);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs1(i);
    }

    for(int i=n-1; i>=0; i--){
        int u = process[i];

        if(color[u]==0){
            qnt_color++;
            dfs2(u);
        }
    }

    vector<bool> indegree(qnt_color, 1);

    for(int u=1; u<=n; u++){
        for(int v: adj[u]){
            if(color[u]!=color[v]){
                indegree[color[v]-1]=0;
            }
        }
    }

    int resp=0;
    for(int i: indegree) resp += (int)i;

    cout << resp << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}