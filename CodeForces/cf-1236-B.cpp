// 00/01/20 // 00:00 XM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;
const int MOD  = (int)(1e9) + 7;


int exp(int a, int b){ // a^b
    if(b==1) return a%MOD;

    a %= MOD;
    if(b&1)
        return (a*exp((a*a)%MOD, b/2))%MOD;
    else
        return (exp((a*a)%MOD, b/2))%MOD;
}


void solve(){
    int n, m;
    cin >> n >> m;

    cout << exp(exp(2,m)-1,n) << endl;
}

int32_t main(){
    fastio;

    solve();

    return 0;
}
