// 14/06/19 // 8:03 PM //

#include <iostream>
#include <cmath>

using  namespace std;

#define  MAXN 100010
#define INF 2000000000

int n, k;
int h[MAXN];

int memo[MAXN];

int funcao(){


    for(int i=2; i<=n; i++){

        memo[i] = INF;

        for(int j=i-1; j>=i-k; j--){
            if(j>=1)
                memo[i] = min(memo[i], abs(h[i]-h[j]) + memo[j]);
            else
                break;
        }
    }

    return memo[n];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> h[i];

    cout << funcao() << "\n";

    return 0;
}
