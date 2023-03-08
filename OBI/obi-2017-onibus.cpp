// 19/09/19 // 9:42 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010
#define pb push_back

int n, a, b;
vector<int> graph[MAXN];
int dist[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;

    for(int i=1; i<n; i++){
        int u, v;

        cin >> u >> v;

        graph[u].pb(v);
        graph[v].pb(u);
    }

    queue<int> fila;

    fila.push(a);
    while(!fila.empty()){

        int u = fila.front();
        fila.pop();

        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];

            if(dist[v]==0 && v!=a){
                dist[v] = dist[u] + 1;

                if(v==b) break;

                fila.push(v);
            }
        }
    }

    cout << dist[b] << "\n";

    return 0;
}
