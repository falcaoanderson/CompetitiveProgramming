// 02/01/19 // 6:52 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e3 + 5;

int n;
int t[MAXN], c[MAXN];
int memo[2][MAXN*2];

void solve(){

    memo[0][4000] = memo[1][4000] = 0;

    for(int j=0; j<=1999; j++) memo[~n&1][j] = INF;

    for(int i=n; i>=1; i--){
        for(int time=0; time<=4000-t[i]; time++){
            if(time-2000>=n-i+1) memo[i&1][time] = 0;

            memo[i&1][time] = min(c[i] + memo[~i&1][time + t[i]], memo[~i&1][time-1]);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> t[i] >> c[i];

    solve();

    cout << memo[1][2000] << endl;

    return 0;
}
