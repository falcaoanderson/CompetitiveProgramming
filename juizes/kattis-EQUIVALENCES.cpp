/*
14/02/24 
Problem: Kattis - Equivalences 
Complexity: O(n+m)
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

const int MAXN = (2e4) + 5;

int outdegree[MAXN], indegree[MAXN], color[MAXN], qnt_color=0;
bool visited[MAXN];
vector<int> adj[MAXN], adj_t[MAXN], dfs_order;

void clear_all(int n){ 
    memset(outdegree, 0, sizeof(outdegree));
    memset(indegree, 0, sizeof(indegree));
    memset(color, 0, sizeof(color));
    qnt_color = 0;

    memset(visited, 0, sizeof(visited));
    
    dfs_order.clear();
    for(int i=1; i<=n; i++){
        adj[i].clear();
        adj_t[i].clear();
    }
}

void dfs1(int u){
    visited[u] = 1;
    
    for(int v: adj[u]){
        if(!visited[v]) dfs1(v);
    }

    dfs_order.PB(u);
}

void dfs2(int u){
    for(int v: adj_t[u]){
        if(color[v]==0){
            color[v] = color[u];
            dfs2(v);
        }
        else if(color[v]!=color[u]){
            //adj_new[color[v]].PB(color[u]);
            
            outdegree[color[v]]++;
            indegree[color[u]]++;
        }
    }
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        clear_all(n);

        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;

            adj[a].PB(b);
            adj_t[b].PB(a);
        }

        //kosaraju
        for(int u=1; u<=n; u++){
            if(!visited[u]) dfs1(u);
        }
        for(int i=sz(dfs_order)-1; i>=0; i--){
            int u = dfs_order[i];

            if(color[u]==0){
                color[u] = (++qnt_color);
                dfs2(u);
            }
        }

        //resposta
        if(qnt_color==1){
            cout << 0 << endl;
            continue;
        }
        
        int x=0, y=0;
        for(int u=1; u<=qnt_color; u++){
            if(indegree[u]==0)  x++;
            if(outdegree[u]==0) y++;
        }

        cout << max(x, y) << endl;
    }

    return 0;
}
