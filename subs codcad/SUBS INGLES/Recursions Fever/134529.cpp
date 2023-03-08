#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 1010

int n, k, m, a[MAXN];
long long dp[MAXN];

int main(){
    memset(dp, 0, sizeof(dp));

    cin >> n >> k >> m;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
        cin >> dp[i];

    for(int i=n+1; i<=k; i++){
        for(int j=1; j<=n;j++){
            dp[i]+= (a[j]*dp[i-j])%m;
            dp[i]=(dp[i])%m;
        }
        //cout << "DP[" << i << "] = " << dp[i] << endl;
    }

    cout  << dp[k] << endl;

    return 0;
}