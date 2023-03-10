#include <iostream>
#define MAXN 105
using namespace std;

int n, qb=0;
int aui[4] = {0,1,0,-1} , auj[4] = {1,0,-1,0};
int m[MAXN][MAXN][2];

bool borda(int t,int i,int j){
    if(i>=0 and i<t and j>=0 and j<t){
        return true;
    }
    return false;
}

void troca(int i,int j){
    m[i][j][1] = 1;
    int x,y;

    for(int k=0; k<4; k++){
        x = i + aui[k];
        y = j + auj[k];
        if(borda(n,x,y) and m[i][j][0] <= m[x][y][0] and m[x][y][1]==0){
            troca(x,y);
        }
    }
    qb++;
}

int main(){
    int i,j;

    cin >> n >> i >> j; i--; j--;
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            cin >> m[a][b][0];
        }
    }
    troca(i,j);

    cout << qb << endl;

    return 0;
}