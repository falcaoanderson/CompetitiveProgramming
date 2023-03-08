// 12/06/20 // 18:25 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

typedef pair<int, int> pii;

const int MAXN = 510;
const int INF  = 0x3f3f3f3f;

int n, e, dist[MAXN];
bool visitado[MAXN];
int grafo[MAXN][MAXN];

void dijkstra(int o){

    for(int i=1; i<=n; i++) dist[i] = INF;
    memset(visitado,   0, sizeof(visitado));

    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0, o});
    dist[o] = 0;

    while(true){
        int atual=-1;

        while(!fila.empty()){
            atual = fila.top().second;
            fila.pop();

            if(!visitado[atual]) break;

            atual = -1;
        }

        if(atual==-1) break;

        visitado[atual] = 1;

        for(int i=1; i<=n; i++){
            if(grafo[atual][i]==INF) continue;

            int v = i;
            int d = grafo[atual][i];

            if(d+dist[atual]<dist[v]){
                dist[v] = d + dist[atual];

                fila.push({dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> e && n!=0){

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                grafo[i][j] = INF;

        for(int i=0; i<e; i++){
            int x, y, h;
            cin >> x >> y >> h;

            grafo[x][y] = h;

            if(grafo[y][x]!=INF){
                grafo[x][y] = grafo[y][x] = 0;
            }
        }

        int k;
        cin >> k;

        while(k--){
            int o, d;
            cin >> o >> d;

            dijkstra(o);

            if(dist[d]!=INF) cout << dist[d] << endl;
            else             cout << "Nao e possivel entregar a carta" << endl;
        }

        cout << endl;
    }

    return 0;
}
