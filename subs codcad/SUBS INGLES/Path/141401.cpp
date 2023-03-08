// 04/03/19 // 11:53 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 310
#define INF 1500000000

#define makep make_pair

typedef pair<int, int> pii;
typedef pair< int, pair<int, int> > piii;

int n, r_max, r_len;
bool visitado[MAXN][MAXN];
int len[MAXN][MAXN], maximo[MAXN][MAXN], peso[MAXN][MAXN];

int aux_x[7] = {-1, 0, 1, 0, 0, 0, 0};
int aux_y[7] = {0, 1, 0, -1, 0, 0, 0};

bool borda(int x, int y){
    if( x>=1 && x<=n && y>=1 && y<=n)
        return 1;
    return 0;
}

int dijikstra(){
    priority_queue< piii, vector<piii>, greater<piii> > fila;

    maximo[1][1] = peso[1][1];

    fila.push( makep( 0, makep(1,1) ) );

    while(true){
        int x=-1, y=-1, new_x, new_y;

        while(!fila.empty()){
            x = fila.top().second.first;
            y = fila.top().second.second;

            fila.pop();

            if(!visitado[x][y]) break;

            x=-1;
        }

        if(x==-1) break;

        visitado[x][y] = 1;

        for(int k=0; k<4; k++){
            new_x = x + aux_x[k];
            new_y = y + aux_y[k];

            if(borda(new_x, new_y) && maximo[x][y]<maximo[new_x][new_y]){
                maximo[new_x][new_y] = max(maximo[x][y], peso[new_x][new_y]);

                fila.push( makep(maximo[new_x][new_y], makep(new_x, new_y)) );
            }
        }
    }

    return maximo[n][n];
}

int BFS(){
    queue<pii> filab;
    memset(visitado, 0, sizeof(visitado));
    len[1][1] = 1;
    visitado[1][1] = 1;

    filab.push( makep(1, 1) );

    while(!filab.empty()){

        if(visitado[n][n]==1) break;

        int x, y, new_x, new_y;

        x = filab.front().first;
        y = filab.front().second;

        filab.pop();

        for(int k=0; k<4; k++){
            new_x = x + aux_x[k];
            new_y = y + aux_y[k];

            if(borda(new_x, new_y) && !visitado[new_x][new_y] && peso[new_x][new_y]<=r_max){
                len[new_x][new_y] = 1 + len[x][y];

                visitado[new_x][new_y] = 1;

                filab.push( makep(new_x, new_y) );
            }

        }
    }

    return len[n][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> peso[i][j];

            maximo[i][j] = INF;
        }
    }

    r_max = dijikstra();
    r_len = BFS();

    cout << r_max << " " << r_len << "\n";

    return 0;
}

