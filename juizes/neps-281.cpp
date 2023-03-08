// 06/06/19 // 9:32 AM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 2010

int p, n;
int valor[MAXN], peso[MAXN];
int memo[MAXN][MAXN];

int knapsack(int i, int falta){
    if(memo[i][falta]>=0) return memo[i][falta];

    if(i>n || falta==0) return 0;

    int pega=0, nao_pega=0;

    nao_pega = knapsack(i+1, falta);

    if(falta-peso[i]>=0){
        pega = valor[i] + knapsack(i+1, falta-peso[i]);

        return memo[i][falta] = max(nao_pega, pega);
    }

    return memo[i][falta] = nao_pega;
}

int main(){
    memset(memo, -1, sizeof(memo));

    cin >> p >> n;

    for(int i=1; i<=n; i++)
        cin >> peso[i] >> valor[i];

    cout << knapsack(1, p) << "\n";

    return 0;
}
