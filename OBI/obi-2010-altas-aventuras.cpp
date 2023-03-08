// 27/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;
const int MOD  = (1e9) + 7;

int memo[MAXN][MAXN];

int solve(int n, int k){
    if(memo[n][k]!=-1) return memo[n][k];

    if(k==1) return n;
    if(n==1) return 1;
    if(n<1) return 0;
    
    memo[n][k] = INF;

    for(int i=1; i<=n; i++){
        memo[n][k] = min(memo[n][k], 1 + max(solve(i-1, k-1), solve(n-i, k)));
    }

    return memo[n][k];
}

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    memset(memo, -1, sizeof(memo));

    cout << solve(n, k) << endl;

    return 0;
}
