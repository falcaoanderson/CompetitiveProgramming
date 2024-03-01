// 29/02/24 //
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

const int MAXN = (5e5) + 5;

int tt=0, n_bcc=0, low[MAXN], in[MAXN];
bool usedEdge[MAXN];
pii edges[MAXN];
vector<int> adj[MAXN], bcc[MAXN];
stack<int> edges_stack;

void dfs(int u){
    low[u] = in[u] = (++tt); 

    if(adj[u].empty()){
        bcc[++n_bcc].PB(u);
        return;
    }

    for(int id: adj[u]){
        int v = (edges[id].FF==u? edges[id].SS: edges[id].FF);

        if(usedEdge[id]) continue;

        usedEdge[id] = 1;
        edges_stack.push(id);

        if(in[v]==0){ // son
            dfs(v);

            low[u] = min(low[u], low[v]);

            if(low[v]>=in[u]){ // u is a articulaction point
                n_bcc++;
                
                while(edges_stack.top()!=id){
                    int e = edges_stack.top();
                    edges_stack.pop();

                    bcc[n_bcc].PB(edges[e].FF);
                    bcc[n_bcc].PB(edges[e].SS);
                }
                int e = edges_stack.top();
                edges_stack.pop();

                bcc[n_bcc].PB(edges[e].FF);
                bcc[n_bcc].PB(edges[e].SS);
            }
        }
        else{ //back-edge
            low[u] = min(low[u], in[v]);
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

        adj[a].PB(i);
        adj[b].PB(i);
        edges[i] = {a, b};
    }

    for(int i=0; i<n; i++){
        if(in[i]==0){
            dfs(i);
        }
    }

    cout << n_bcc << endl;
    for(int i=1; i<=n_bcc; i++){
        sort(bcc[i].begin(), bcc[i].end());
        int SZ = size(bcc[i]);

        vector<int> aux;
        for(int j=0; j<SZ; j++){
            if(j==SZ-1 || bcc[i][j]!=bcc[i][j+1]) aux.PB(bcc[i][j]);
        }

        cout << size(aux) << " ";
        for(int x: aux) cout << x << " ";
        cout << endl;
    }

    return 0;
}