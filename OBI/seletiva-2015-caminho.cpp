// 17/12/19 // 3:32 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define mp make_pair
#define pii pair<int, int>

const int MAXN = 3e2 + 10;
const int MAXV = 1e9;

int n;
int peso[MAXN][MAXN], dist[MAXN][MAXN];
int aux_x[] = {-1, 0, 1,  0, 0 ,0};
int aux_y[] = { 0, 1, 0, -1, 0, 0};
bool visitado[MAXN][MAXN];

bool no_grid(int x, int y){
    if( x < 1 || x > n || y < 1 || y > n)
        return 0;
    return 1;
}

int bfs(int mmax){
    queue< pii > fila;
    memset(dist, 0, sizeof(dist));
    memset(visitado, 0, sizeof(visitado));
    dist[1][1] = 1;

    if(peso[1][1]<=mmax) fila.push( mp(1,1) );

    while(!fila.empty()){
        int x = fila.front().first, y = fila.front().second;
        fila.pop();

        for(int k=0; k<4; k++){
            int nx = x + aux_x[k];
            int ny = y + aux_y[k];

            if(no_grid(nx, ny) && !visitado[nx][ny] && peso[nx][ny]<=mmax){
                visitado[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;

                fila.push(mp(nx, ny));
            }
        }
    }

    return dist[n][n];
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> peso[i][j];

    int ini=1, fim = MAXV, r_max, r_len;

    while(ini<=fim){
        int meio = (ini+fim)/2;

        int tdist = bfs(meio);

        if(tdist==0){       // se nao existe caminho pra esse max
            ini = meio + 1; // aumento o max
        }
        else{               // se existe
            fim = meio-1;   // diminuo e tento achar uma resposta ainda melhor
            r_max = meio;
            r_len = tdist;
        }
    }

    cout << r_max << " " << r_len << endl;

    return 0;
}
