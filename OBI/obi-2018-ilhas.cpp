// 18/04/19 // 5:39 PM //

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000010
#define MAXN 1010
#define PB push_back
#define MP make_pair

typedef pair<int, int> pii;

int n, m, inicial;
int distancia[MAXN];
bool visitado[MAXN];
vector<pii> vizinhos[MAXN];

priority_queue< pii, vector<pii>, greater<pii> > fila;

void dijikstra(int inicial){

    for(int i=1; i<=n; i++) distancia[i] = INF;

    distancia[inicial] = 0;

    fila.push( MP(0, inicial) );

    while(true){
        int atual=-1;

        while(!fila.empty()){
            atual = fila.top().second;
            fila.pop();

            if(!visitado[atual]) break;
            atual = -1;
        }

        if(atual == -1) break;

        visitado[atual] = 1;

        for(int i=0; i<vizinhos[atual].size(); i++){
            int temp = vizinhos[atual][i].first;
            int dist = vizinhos[atual][i].second + distancia[atual];

            if(dist < distancia[temp]){
                distancia[temp] = dist;

                fila.push( MP(dist, temp) );
            }
        }
    }

}

int main(){

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, c;

        cin >> a >> b >> c;

        vizinhos[a].PB( MP(b, c) );
        vizinhos[b].PB( MP(a, c) );
    }

    cin >> inicial;

    dijikstra(inicial);

    return 0;
}
