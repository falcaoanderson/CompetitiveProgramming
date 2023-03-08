// 23/03/2018 // 4:31 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 110
#define INF 1999999999

int n;
int p_caixa[MAXN][MAXN];
int soma[MAXN][MAXN];

int memo[MAXN][MAXN][MAXN];

int funcao(int dir, int esq, int fila){
    if(memo[dir][esq][fila]>-1) return memo[dir][esq][fila];

    if(fila>n) return memo[dir][esq][fila]=0;

    int opc_1 = INF, opc_2=INF;

    if(dir<n)
        opc_1 = soma[fila][dir+1] + funcao(dir+1, esq, fila+1);
    if(esq>1)
        opc_2 = soma[fila][esq-1] + funcao(dir, esq-1, fila+1);

    return memo[dir][esq][fila] = min(opc_1, opc_2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> p_caixa[i][j];

    for(int j=1; j<=n; j++)
        for(int i=n; i>=1; i--)
            soma[i][j] = p_caixa[i][j] + soma[i+1][j];

    int menor = INF;
    int temp = INF;
    for(int j=1; j<=n; j++){
        temp = soma[1][j] + funcao(j, j, 2);

        menor = min(temp, menor);
    }

    cout << menor << "\n";

    return 0;
}
