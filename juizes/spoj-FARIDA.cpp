#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10010
#define MAXP 2

int n, moeda[MAXN];
long long memo[MAXN][MAXP];

long long farida(int i, int p){
    if(memo[i][p]!=-1)return memo[i][p];

    if(i>n)return memo[i][p]=0;

    long long nao_pega = farida(i+1,0);

    if(p==0){
        long long pega = moeda[i] + farida(i+1, 1);

        return memo[i][p] = max(pega,nao_pega);
    }

    return memo[i][p] = nao_pega;
}


int main(){
    int t;
    cin >> t;

    for(int j=1; j<=t; j++){
        memset(memo, -1, sizeof(memo));
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> moeda[i];

        cout << "Case " << j << ": "<< farida(1,0) << endl;
    }

    return 0;
}
