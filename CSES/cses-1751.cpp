// 10/11/20 // xx:xx PM //

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
const int MAXN = (2e5) + 10;

int n, adj[MAXN], visited[MAXN], dist[MAXN];
int cycle[MAXN], tam_cycle[MAXN], qnt_cycle=0;
int start_cycle=0, end_cycle=0;

bool pre_dfs(int u){
    visited[u] = 1;

    int v = adj[u];

    bool flag = 0;

    if(visited[v]==0){
        flag = pre_dfs(v);
    }
    else if(visited[v]==1){
        start_cycle = v;
        end_cycle = u;
        flag = 1;
    }

    visited[u] = 2;
    return flag;
}

void dist_dfs(int u){
    if(cycle[u]!=0 || dist[u]!=0) return;
    
    int v = adj[u];
    dist_dfs(v);

    dist[u] = dist[v] + 1;
    cycle[u] = cycle[v];
}

int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> adj[i];

    for(int i=1; i<=n; i++){ // marcar todos os ciclos
        if(visited[i]==0){
            if(pre_dfs(i)){
                
                qnt_cycle++;
                int u = start_cycle, tam=0;
                
                while(u!=end_cycle){
                    cycle[u] = qnt_cycle;
                    u = adj[u];
                    tam++;
                }
                cycle[u] = qnt_cycle;

                tam_cycle[qnt_cycle] = tam+1;
            }
        }
    }

    for(int i=1; i<=n; i++){ // define distancia ate o ciclo e em qual ciclo ele chega
        if(cycle[i]==0){
            dist_dfs(i);
        }
    }
    
    for(int i=1; i<=n; i++)
        cout << dist[i] + tam_cycle[cycle[i]] << " ";
    cout << endl;

    return 0;
}
