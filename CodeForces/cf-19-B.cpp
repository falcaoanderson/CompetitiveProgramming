// 02/01/19 // 5:34 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e3 + 10;

int n;
int t[MAXN], c[MAXN];
int memo[MAXN][MAXN*2];

int solve(int i, int time){
    if(time>=4000) return 0;

    if(memo[i][time]!=-1) return memo[i][time];

    if(i>n){
        if(time>=2000) return memo[i][time] = 0;
        else           return memo[i][time] = INF;
    }

    if(time-2000==n-i+1) return memo[i][time] = 0;

    return memo[i][time] = min(c[i] + solve(i+1, time + t[i]), solve(i+1, time-1));
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> t[i] >> c[i];

    cout << solve(1, 2000) << endl;

    return 0;
}
