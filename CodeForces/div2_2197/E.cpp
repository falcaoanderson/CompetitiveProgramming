/*
12/02/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

void dfs(int u, vector<vector<int>> &adj, vector<int> &acc, vector<int> &visited){
    if(acc[u] != 0) return;
    acc[u] = 1;
    visited[u] = 1;
    for(int v: adj[u]){
        dfs(v, adj, acc, visited);
        acc[u] += acc[v];
    }
}

void solve(){
    int n;
    cin >> n;

    int m=0;
    vector<int> visited(n+1), acc(n+1);
    vector<vector<int>> adj(n+1);
    
    visited[1] = 2;
    int k = 2;
    
    while(1){
        // condicao de parada
        bool flag_stop = 1;
        for(int i=1; i<=n; i++) flag_stop = (flag_stop && (visited[i]==1));
        if(flag_stop) break;

        // pergunta
        cout << "? " << k << endl;
        int q;
        cin >> q;
        vector<int> path(q);
        for(int i=0; i<q; i++) cin >> path[i];

        if(q==0) break; // ja processou tudo
        
        // encontrar vertices que ja foram explorados completamente
        for(int i=1; i<=n; i++){
            if(visited[i] == 2){
                bool flag = 0;
                for(int j: path) flag = (flag || (j==i));
                
                if(!flag){
                    // visited[i] = 1;
                    dfs(i, adj, acc, visited);
                }
            }
        }

        // adicionamos a aresta nova no grafo, se nao foi adicionada anteriormente
        if(q > 1){
            int u = path[q-2], v = path[q-1];
            bool flag_add = 1;
            for(int x: adj[u]) flag_add = (flag_add & (x != v));
            
            if(flag_add){
                adj[u].PB(v);
                m++;
            }
        }

        // se tem algum vertice que ja foi explorado completamente, então pulamos no 'k'
        bool flag_skip = 0;
        for(int i=0; i<q; i++){
            int u = path[i];

            if(visited[u] == 1){
                k += acc[u];
                flag_skip = 1;

                while(q==1 && u+1<=n && visited[u+1]==1){
                    k += acc[++u];
                }
                if(q==1 && u+1<=n && visited[u+1]==0){
                    visited[u+1] = 2;
                }

                break;
            }

            visited[u] = 2;
        }

        if(!flag_skip){
            k++;
        }
        if(flag_skip && q==1){
            k++;
        }
    }
    
    // responde
    cout << "! " << m << endl;
    for(int i=1; i<=n; i++){
        for(int v: adj[i]){
            cout << i << " " << v << endl;
        }
    }    
}

int main(){
    // fast_io;

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
