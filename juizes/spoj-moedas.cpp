#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXM 110
#define MAXV 50010

int m, n, moedas[MAXM];

int memo[MAXM][MAXV];

int funcao(int i, int val){
    if(memo[i][val]!=-1)return memo[i][val];

    if(val==0)return memo[i][val] = 0;
    if(i>n)return memo[i][val] = MAXV;

    int nao_coloca = funcao(i+1,val);

    if(moedas[i]<=val){
        int coloca = 1 + funcao(i, val-moedas[i]);

        return memo[i][val]=min(coloca, nao_coloca);
    }

    return memo[i][val]=nao_coloca;
}

int main(){

    while(true){

    cin >> m;
    if(m==0)break;
    cin >>n;

    memset(memo, -1,sizeof(memo));

    for(int i=1; i<=n; i++)
        cin >> moedas[i];

    int resposta = funcao(1,m);

    if (resposta<=50000)
        cout << resposta << endl;
    else
        cout << "Impossivel\n";

    }

    return 0;
}
