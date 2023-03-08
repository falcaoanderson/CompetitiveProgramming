// 28/05/19 // 7:27 PM //

#include <iostream>

using namespace std;

#define MAXN 110

int n;
char matriz[MAXN][MAXN];

int main(){

    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> matriz[i][j];

    int pontos=0, max_pontos=0;

    for(int i=1; i<=n; i++){
        if(i%2!=0)
            for(int j=1; j<=n; j++){
                if(matriz[i][j]=='o') pontos++;
                else if(matriz[i][j]=='A') pontos = 0;

                max_pontos = max(max_pontos, pontos);
            }
        else
            for(int j=n; j>=0; j--){
                if(matriz[i][j]=='o') pontos++;
                else if(matriz[i][j]=='A') pontos = 0;

                max_pontos = max(max_pontos, pontos);
            }

     }

     cout << max_pontos << "\n";

     return 0;
}
