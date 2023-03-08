// 17/11/20 // xx:xx PM //

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
const int MAXN = (1e6) + 10;
const int MOD  = (1e9) + 7;

ll memo[MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;

    memo[0] = 1;
    for(int i=2; i<=n; i++)
        memo[i] = ((i-1) * ((memo[i-1] + memo[i-2])%MOD))%MOD;
    
    cout << memo[n] << endl;

    return 0;
}
