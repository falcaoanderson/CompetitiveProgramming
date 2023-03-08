#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXM 1010
#define MAXV 100010

int m, n, moedas[MAXM];
int memo[MAXM][MAXV];

int funcao(int i, int val){
    if(memo[i][val]!=-1)return memo[i][val];

    if(val==0)return memo[i][val] = 0;
    if(i>n)return memo[i][val] = MAXV;

    int coloca=100, nao_coloca;

    nao_coloca = funcao(i+1,val);

    if(nao_coloca==0)return memo[i][val]=nao_coloca;

    if(moedas[i]<=val)
        coloca = funcao(i+1, val-moedas[i]);

    if(coloca==0)return memo[i][val]=coloca;

    return memo[i][val] = 100;
}


int main(){
    memset(memo, -1,sizeof(memo));

    cin >> m >> n;

    for(int i=1; i<=n; i++)
        cin >> moedas[i];

    if (funcao(1,m)==0)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
