// 01/02/19 // 7:26 //

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 1010
#define INF  999999999
typedef pair<int, int> PAR;


int n, m;
int dist[MAXN];
bool visitado[MAXN];
vector<PAR> vizinhos[MAXN];

priority_queue< PAR, vector< PAR >, greater< PAR > > fila;

void Dijkstra(){
    for(int i=0; i<=n+1; i++) dist[i]=INF;
    dist[0]=0;

    fila.push( PAR(0,0) );

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

        int temp, new_dist;
        for(int i=0; i<vizinhos[atual].size(); i++){
            temp     = vizinhos[atual][i].second;
            new_dist = dist[atual] + vizinhos[atual][i].first;

            if(new_dist < dist[temp]){
                dist[temp]=new_dist;

                fila.push( PAR(new_dist, temp));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, d;

        cin >> a >> b >> d;

        vizinhos[a].push_back( PAR(d, b) );
        vizinhos[b].push_back( PAR(d, a) );
    }

    Dijkstra();

    cout << dist[n+1] << "\n";

    return 0;
}
