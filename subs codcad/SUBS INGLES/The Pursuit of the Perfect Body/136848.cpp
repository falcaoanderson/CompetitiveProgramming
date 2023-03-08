// 23/01/19 // 7:38 PM //

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 2010

int n, c;
int peso[MAXN];
int valor[MAXN];

int memo[MAXN][MAXN];

int funcao(int i, int cap){
    if(memo[i][cap]>=0) return memo[i][cap];

    if(i>n || cap<=0) return memo[i][cap]=0;

    int nao_coloco = funcao(i+1, cap);

    if(cap>=peso[i]){
        int coloco = valor[i] + funcao(i+1, cap-peso[i]);

        return memo[i][cap] = max(coloco, nao_coloco);
    }

    return memo[i][cap] = nao_coloco;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> c >> n;

    for(int i=1; i<=n; i++)
        cin >> peso[i] >> valor[i];

    cout << funcao(1, c) << "\n";

    return 0;
}
