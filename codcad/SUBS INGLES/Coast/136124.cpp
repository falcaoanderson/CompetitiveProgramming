// 16/01/19 // 0 AM //

#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 1010

char temp;
bool mapa[MAXN][MAXN];
int n, m, i, j;

int main(){
    cin >> n >> m;
    getchar();

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            temp=getchar();
            if(temp=='.') mapa[i][j]=0;
            else          mapa[i][j]=1;
        }
        getchar();
    }

    int cont = 0;

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(mapa[i][j]==1 && (mapa[i-1][j]==0 || mapa[i+1][j]==0 || mapa[i][j-1]==0 || mapa[i][j+1]==0))
                cont++;
        }
    }

    cout << cont << "\n";

    return 0;
}
