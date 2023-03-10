// 01/02/19 // 8:35 PM //

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 260
#define INF  999999999
typedef pair<int, int> PAR;


int n, m, c, k;
int dist[MAXN];
int rota[MAXN];
int pedagio[MAXN][MAXN];
bool visitado[MAXN];
vector<PAR> vizinhos[MAXN];

priority_queue< PAR, vector< PAR >, greater< PAR > > fila;

void Dijkstra(int origem){
    for(int i=0; i<n; i++){
        dist[i]  = INF;
        visitado[i] = 0;
    }

    dist[origem]=0;

    fila.push( PAR(0, origem) );

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

            if(temp<c-1){
                new_dist = dist[atual] + vizinhos[atual][i].first + rota[temp];

                if(new_dist < dist[c-1]){
                    dist[c-1] = new_dist;
                }
                continue;
            }

            new_dist = dist[atual] + vizinhos[atual][i].first;

            if(new_dist < dist[temp]){
                dist[temp]  = new_dist;

                fila.push( PAR(new_dist, temp));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> m >> c >> k){
        if(n==0 && m==0 && c==0 && k==0) break;

        for(int i=0; i<n; i++) vizinhos[i].clear();

        for(int i=0; i<m; i++){
            int a, b, d;

            cin >> a >> b >> d;

            if(a>b)swap(a,b);

            vizinhos[a].push_back( PAR(d, b) );
            vizinhos[b].push_back( PAR(d, a) );
            pedagio[a][b]=d;
            pedagio[b][a]=d;
        }


        rota[c-1]=0;
        for(int i=c-2; i>=0; i--){
            rota[i] = rota[i+1] + pedagio[i+1][i];
        }
        /*
        for(int i=0; i<=c-1; i++){
            cout << rota[i] << " ";
        }
        cout << "\n";
        */


        Dijkstra(k);

        cout << dist[c-1] << "\n";

    }

    return 0;
}
