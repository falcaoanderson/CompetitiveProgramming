#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1010

struct Objeto{
    int peso, valor;
};

int t, n, g, familia[110], max_valor, dp[MAXN][MAXN];
Objeto v[MAXN];

int funcao(int i, int c){ // i-posicao // c-capacidade
    if(dp[i][c]>=0)return dp[i][c];

    if(i>n or c==0)return dp[i][c]=0;

    int nao_coloca = funcao(i+1,c);

    if(c>=v[i].peso){
        int coloca = v[i].valor + funcao(i+1, c-v[i].peso);

        return dp[i][c]=max(coloca,nao_coloca);
    }

    return dp[i][c]=nao_coloca;
}


int main(){
    cin >> t;

    for(int j=0; j<t; j++){
        memset(dp, -1, sizeof(dp));
        cin >> n;

        for(int i=1; i<=n; i++)
            cin>> v[i].valor >> v[i].peso;

        cin >> g;

        for(int i=1; i<=g; i++)
            cin >> familia[i];

        max_valor = 0;

        for(int i=1; i<=g; i++)
            max_valor += funcao(1,familia[i]);

        cout << max_valor << endl;
    }

    return 0;
}
