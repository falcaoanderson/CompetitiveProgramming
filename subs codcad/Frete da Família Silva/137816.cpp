// 05/02/19 // 8:07 PM //

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAXV 1010
#define INF 999999999
typedef pair<int, int> PAR;

int nver, nare;
int visitado[MAXV];
int dist[MAXV];
vector<PAR> vizinhos[MAXV];

priority_queue< PAR, vector<PAR>, greater<PAR> > fila;

int Prim(){
    for(int i=0; i<nver; i++) dist[i]=INF;
    dist[0]=0;

    fila.push( PAR(0, 0) );
    int arvore=0;

    while(true){
        int atual=-1;

        while(!fila.empty()){
            atual = fila.top().second;
            fila.pop();

            if(!visitado[atual]) break;

            atual=-1;
        }

        if(atual==-1) break;
        arvore += dist[atual];

        visitado[atual] = 1;

        for(int i=0; i<vizinhos[atual].size(); i++){
            int v_temp = vizinhos[atual][i].second;
            int d_temp = vizinhos[atual][i].first;

            if(dist[v_temp]>d_temp && !visitado[v_temp]){
                dist[v_temp] = d_temp;

                fila.push( PAR(d_temp, v_temp) );
            }
        }
    }

    return arvore;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nver >> nare;

    for(int i=0; i<nare; i++){
        int a, b, d;

        cin >> a >> b >> d;

        vizinhos[a].push_back( PAR(d, b) );
        vizinhos[b].push_back( PAR(d, a) );
    }

    cout << Prim() << "\n";

    return 0;
}
