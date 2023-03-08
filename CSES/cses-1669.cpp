// 04/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m;
int visitado[MAXN], ant[MAXN];
vector<int> adj[MAXN];

pii dfs(int u, int time){
    visitado[u] = time;

    for(int v: adj[u]){
        if(visitado[v]==time && v!=ant[u]){ // achei ciclo
            return pii(u, v);
        }
        if(visitado[v]==0){
            ant[v] = u;
            pii temp = dfs(v, time);
            if(temp.first!=0) return temp;
        }
    }

    return pii(0, 0);
}

int main(){
    fast_io;
    
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }    

    for(int i=1; i<=n; i++){
        if(visitado[i]==0){
            pii temp = dfs(i, i);
            if(temp.first == 0) continue;

            int u = temp.first;
            vector<int> caminho;
            
            caminho.pb(temp.second);
            while(u!=temp.second){
                caminho.pb(u);
                u = ant[u];
            }
            caminho.pb(temp.second);

            cout << caminho.size() << endl;
            for(int i: caminho) cout << i << " ";
            cout << endl;
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;

    return 0;
}
