// 23/11/20 // xx:xx PM //
// solucao nao otimizada O(n^3)

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back

const int MAXN = (1e3) + 10;

int n, m, qnt_true;
bool is_true[MAXN], fontes[MAXN][MAXN], grau[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int fonte){
    for(int v: adj[u]){
        if(fontes[v][fonte]) continue;

        fontes[v][fonte] = 1;
        dfs(v, fonte);
    }
}

int main(){
    fast_io;
    
    cin >> n >> m >> qnt_true;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        grau[b] = 1;
    }

    for(int i=1; i<=n; i++)
        if(!grau[i]){
            fontes[i][i] = 1;
            dfs(i, i);
        }

    for(int i=1; i<=qnt_true; i++){
        int u;
        cin >> u;

        is_true[u] = 1;

        for(int j=1; j<=n; j++){
            if(is_true[j]) continue;

            bool flag = true;

            for(int k=1; k<=n && flag; k++)
                if(fontes[u][k] && !fontes[j][k]) flag = false; 
            
            is_true[j] = flag;
        }

    }
    
    for(int i=1; i<=n; i++) if(is_true[i]) cout << i << " ";
    cout << endl;
    
    return 0;
}
