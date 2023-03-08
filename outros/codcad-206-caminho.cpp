// 03/03/19 // 8:17 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 310
#define INF 1500000000

#define makep make_pair

typedef pair<int, int> pii;
typedef pair< pair<int, int>, pair<int, int> > piiii;

int n;
bool visitado[MAXN][MAXN];
int len[MAXN][MAXN], maximo[MAXN][MAXN], peso[MAXN][MAXN];

int aux_x[7] = {-1, 0, 1, 0, 0, 0, 0};
int aux_y[7] = {0, 1, 0, -1, 0, 0, 0};
priority_queue< piiii, vector<piiii>, greater<piiii> > fila;

bool borda(int x, int y){
    if( x>=1 && x<=n && y>=1 && y<=n)
        return 1;
    return 0;
}

void dijikstra(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            maximo[i][j] = INF;
            len[i][j]    = INF;
         }
    }
    maximo[1][1] = peso[1][1];
    len[1][1] = 1;
    fila.push( makep( makep(0,0), makep(1,1) ) );

    while(true){
        int x = -1, y = -1;

        while(!fila.empty()){
            x = fila.top().second.first;
            y = fila.top().second.second;

            fila.pop();

            if(!visitado[x][y]) break;

            x = y = -1;
        }

        if(x==-1 && y==-1) break;

        visitado[x][y] = 1;

        for(int k=0; k<4; k++){
            int new_x = x + aux_x[k];
            int new_y = y + aux_y[k];

            if(!borda(new_x, new_y)) continue;

            if(maximo[x][y]<maximo[new_x][new_y]){

                maximo[new_x][new_y] = max(maximo[x][y], peso[new_x][new_y]);

                len[new_x][new_y] = 1 + len[x][y];

                fila.push( makep( makep(maximo[new_x][new_y], len[new_x][new_y] ), makep(new_x, new_y)) );
            }
            else if(maximo[x][y]==maximo[new_x][new_y] && len[x][y]<len[new_x][new_y]){
                len[new_x][new_y] = 1 + len[x][y];

                fila.push( makep( makep(maximo[new_x][new_y], len[new_x][new_y] ), makep(new_x, new_y)) );
            }
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> peso[i][j];
        }
    }

    dijikstra();

    cout << maximo[n][n] << " " << len[n][n] << "\n";

    return 0;
}
