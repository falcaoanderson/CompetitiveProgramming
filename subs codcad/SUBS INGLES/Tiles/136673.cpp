// 21/01/19 // 4:31 PM //

#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 210

int h, l;
int matriz[MAXN][MAXN];
int conexa[MAXN][MAXN];
int aux[5]={-1, 0, 1, 0,  0};
int auy[5]={0, 1, 0, -1,  0};

int DFS(int x, int y){
    conexa[x][y]=1;

    int total=0;

    for(int i=0; i<4; i++){
        int nx = x + aux[i];
        int ny = y + auy[i];

        if(matriz[x][y] == matriz[nx][ny] && conexa[nx][ny]==0){
            total += 1 + DFS(nx,ny);
        }

    }

    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(matriz, -1, sizeof(matriz));

    cin >> h >> l;

    for(int i=1; i<=h; i++)
        for(int j=1; j<=l; j++)
            cin >> matriz[i][j];

    int menor = 40010;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=l; j++){
            if(conexa[i][j]==0){
                int temp = DFS(i,j);
                if(temp<menor) menor = temp;
            }
        }
    }

    cout << menor+1 << "\n";

    return 0;
}
