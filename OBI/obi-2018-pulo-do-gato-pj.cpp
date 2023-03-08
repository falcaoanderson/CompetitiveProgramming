// 21/03/2019 // 8:00 PM //
// reciclado // 01/05/2020 //


#include <iostream>
#include <queue>

using namespace std;

#define MAXLC 10010

typedef pair<int, int> par;

int l, c;
bool piso[10][MAXLC];
bool visitado[10][MAXLC];
int dist[10][MAXLC];

queue< par > fila;

void BFS(){
    visitado[2][2] = 1;

    fila.push( par(2,2) );

    while( !fila.empty() ){
        int x, y;

        x = fila.front().first;
        y = fila.front().second;

        fila.pop();

        for(int i=x-2; i<=x+2; i++){
            for(int j=y-2; j<=y+2; j++){

                if(!visitado[i][j] && piso[i][j]==1){

                    visitado[i][j]=1;
                    dist[i][j] = dist[x][y] + 1;

                    if(i==l+1 && j==c+1) return;

                    fila.push( par(i,j) );
                }
            }
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c;
    l = 1;

    for(int i=2; i<=l+1; i++)
        for(int j=2; j<=c+1; j++)
            cin >> piso[i][j];

    BFS();

    if(dist[l+1][c+1]!=0)
        cout << dist[l+1][c+1] << "\n";
    else
        cout << "-1\n";

    return 0;
}

