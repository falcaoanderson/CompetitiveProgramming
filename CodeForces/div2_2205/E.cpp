/*
02/03/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (8e3) + 5;
const int MOD  = 998244353;

int n, v[MAXN], memo[MAXN];

int dp(int i){
    if(memo[i] != -1) return memo[i];

    if(i==n) return 1;

    int l = i, r = i;
    vector<int> z(n);
    for(int j=i+1; j<n; j++){
        z[j] = max(0, min(r - j, z[i + (j - l)]));

        while(j + z[j] < n && v[j + z[j]] == v[i + z[j]]){
            z[j]++;
        }

        if(j + z[j] > r){
            r = j + z[j];
            l = j;
        }
    }

    r = i;
    memo[i] = dp(i+1);
    for(int j=i+1; j<n; j++){
        if(j > r && z[j] == 0){
            memo[i] = (memo[i] + dp(j+1)) % MOD;
        }
        if(j + z[j] - 1 > r){
            r = j + z[j] - 1;
        }
    }
    return memo[i];
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> v[i];
    memset(memo, -1, sizeof(memo));

    cout << dp(0) << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
