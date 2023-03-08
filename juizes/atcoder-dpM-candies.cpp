// 01/02/20 // 5:08 PM //

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = (int)1e2 + 10;
const int MAXK = (int)1e5 + 10;
const int MOD  = (int)1e9 + 7;

int n, k, a[MAXN];
int memo[2][MAXK], prefix[MAXK];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];

    memo[0][0] = memo[1][0] = 1;
    for(int j=0; j<=min(k,a[1]); j++)  memo[1][j] = 1;

    // i = 1
    prefix[0] = memo[1][0];
    for(int j=1; j<=k; j++) prefix[j] = memo[1][j] + prefix[j-1];

    for(int i=2; i<=n; i++){

        for(int j=0; j<=k; j++){

            if(j<=a[i])
                memo[i&1][j] = prefix[j];
            else
                memo[i&1][j] = (prefix[j] - prefix[j-a[i]-1] + MOD)%MOD;

        }

        prefix[0] = memo[i&1][0];
        for(int j=1; j<=k; j++)
            prefix[j] = (memo[i&1][j] + prefix[j-1])%MOD;
    }

    cout << memo[n&1][k] << endl;

    return 0;
}
