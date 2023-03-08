// 20/01/19 // 9:31 PM//

#include <iostream>

using namespace std;

#define MAXN 1010

int n, m, p1, p2;
int matriz[MAXN][MAXN];

int aux[4] = {-1,0,1,0};
int auj[4] = {0,1,0,-1};

void DFS(int x, int y, int passos){
    passos++;

    if(matriz[x][y]==3){
        cout << passos << "\n";
        return;
    }

    matriz[x][y] = 0;

    for(int i=0; i<4; i++){
        int new_x = x + aux[i];
        int new_y = y + auj[i];

        if(matriz[new_x][new_y]!=0)
            DFS(new_x, new_y, passos);
    }
}

int main(){
    cin >> n >> m;

    int temp;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> temp;
            matriz[i][j] = temp;
            if(temp==2){
                p1=i;
                p2=j;
            }
        }
    }

    DFS(p1, p2, 0);

    return 0;
}
