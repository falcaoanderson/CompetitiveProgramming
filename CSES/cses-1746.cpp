// 01/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MOD  = (1e9) + 7;
const int MAXN = (1e5) + 10;
const int MAXV = (1e2) + 10;

ll memo[MAXN][MAXV];

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    if(v[1]==0)
        for(int i=1; i<=m; i++) memo[1][i] = 1LL;
    else
        memo[1][v[1]] = 1LL;

    for(int i=2; i<=n; i++){ 
        if(v[i]!=0)
            memo[i][v[i]] = ((memo[i-1][v[i]-1] + memo[i-1][v[i]])%MOD + memo[i-1][v[i]+1])%MOD;
        else 
            for(int j=1; j<=m; j++)
                memo[i][j] = ((memo[i-1][j-1] + memo[i-1][j])%MOD + memo[i-1][j+1])%MOD;   
    }

    ll ans = 0LL;
    for(int j=1; j<=m; j++) ans = (ans + memo[n][j])%MOD;

    cout << ans << endl;

    return 0;
}
