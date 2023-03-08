// 11/06/19 // 7:37 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 30
#define MAXM 264010
#define INF 1000000

int n;
int valor[MAXN][MAXN];

int memo[MAXM];

int funcao(int i, int mask){
    if(memo[mask]>=0) return memo[mask];

    if(i>n) return 0;

    int temp=INF;

    for(int j=1; j<=n; j++)
        if( (mask&(1<<j-1))==0 )
            temp = min( temp, valor[i][j] + funcao(i+1, mask|(1<<j-1)) );

    return memo[mask] = temp;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n && n){

    memset(memo, -1, sizeof(memo));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> valor[i][j];

    cout << funcao(1, 0) << "\n";

    }

    return 0;
}

