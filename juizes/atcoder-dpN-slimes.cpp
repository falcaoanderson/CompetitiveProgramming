// 00/01/20 // 00:00 XM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (int)(4e2) + 10;

int n;
int memo[MAXN][MAXN], prefix[MAXN];

int solve(int i, int j){
    if(memo[i][j]!=-1) return memo[i][j];

    if(i==j) return memo[i][j] = 0;

    memo[i][j] = INF;
    for(int k=i; k<j; k++)
        memo[i][j] = min(memo[i][j], solve(i, k) + solve(k+1, j)+prefix[j]-prefix[i-1]);

    return memo[i][j];
}

int32_t main(){
    fastio;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> prefix[i];
        prefix[i]+=prefix[i-1];
    }

    memset(memo, -1, sizeof(memo));
    cout << solve(1, n) << endl;

    return 0;
}
