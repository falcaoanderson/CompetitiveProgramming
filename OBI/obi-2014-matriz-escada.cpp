// 28/05/19 // 8:08 PM //

#include <iostream>

using namespace std;

#define MAXN 510

int n, m;
int matriz[MAXN][MAXN];

int main(){

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> matriz[i][j];

    int menor_ant=-1, menor_atual;

    for(int i=1; i<=n; i++){
        menor_atual=m+i;

        for(int j=m; j>=1; j--){
            if(matriz[i][j]!=0)
                menor_atual = j;
        }

        if(menor_atual<=menor_ant){
            cout << "N\n";
            return 0;
        }
        menor_ant=menor_atual;
    }

    cout << "S\n";

    return 0;
}
