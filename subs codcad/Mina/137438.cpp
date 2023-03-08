// 01/02/19 // 5:25 PM //

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999999
#define MAXN 110
typedef pair<int, int> PAR;
typedef pair<int, pair<int, int> > PARP;

int n;
int matriz[MAXN][MAXN], dist[MAXN][MAXN];
bool visitado[MAXN][MAXN];

int aux[6] = {-1, 0, 1, 0,  0,0};
int auy[6] = {0, 1, 0, -1,  0,0};


bool borda(int i, int j){
    if(i>=1 && i<=n && j>=1 && j<=n)
        return true;

    return false;
}

void Dijkstra(){
    dist[1][1] = 0;

    priority_queue< PARP, vector<PARP>, greater<PARP> > fila;

    fila.push( make_pair( 0, make_pair(1,1) ) );

    while(true){
        int x = -1, y;

        while(!fila.empty()){
            x = fila.top().second.first;
            y = fila.top().second.second;
            fila.pop();

            if(!visitado[x][y]) break;

            x = -1;
        }

        if(x==-1) break;

        visitado[x][y] = 1;

        int new_x, new_y, new_dist;
        for(int i=0; i<4; i++){
            new_x = x + aux[i];
            new_y = y + auy[i];

            new_dist = dist[x][y] + matriz[new_x][new_y];

            if(new_dist < dist[new_x][new_y] && borda(new_x, new_y)){

                dist[new_x][new_y] = new_dist;

                fila.push( make_pair( new_dist , make_pair( new_x, new_y )) );
            }

        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> matriz[i][j];
            dist[i][j]=INF;
        }
    }

    Dijkstra();

    cout << dist[n][n] << "\n";

    return 0;
}
