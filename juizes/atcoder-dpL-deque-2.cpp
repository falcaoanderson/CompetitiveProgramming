// 26/01/20 // 12:19 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long

const int MAXN = (int)(3e3) + 10;

int n, a[MAXN];
int memo[2][MAXN];

int32_t main(){
    fastio;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int l=n; l>=1; l--){
        for(int r=l; r<=n; r++){
            if(((r-l+1)&1)==(n&1))
                memo[l&1][r] = max(a[l] + memo[~l&1][r], a[r] + memo[l&1][r-1]);
            else
                memo[l&1][r] = min(memo[~l&1][r] - a[l], memo[l&1][r-1] - a[r]);
        }
    }

    cout << memo[1][n] << endl;

    return 0;
}

