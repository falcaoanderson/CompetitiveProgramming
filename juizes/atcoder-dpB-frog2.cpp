// 14/06/19 // 8:03 PM //

#include <iostream>
#include <cmath>
#include <cstring>

using  namespace std;

#define  MAXN 100010
#define INF 2000000000

int n, k;
int h[MAXN];

int memo[MAXN];

int funcao(int i){
    if(memo[i]>=0) return memo[i];

    if(i>=n) return memo[i] = 0;

    memo[i] = INF;

    for(int j=1; j<=k; j++){
        if( (i+j)<=n )
            memo[i] = min(memo[i], abs(h[i]-h[i+j]) + funcao(i+j));
        else
            break;
    }

    return memo[i];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> h[i];

    cout << funcao(1) << "\n";

    return 0;
}
