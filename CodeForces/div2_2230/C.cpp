/*
18/05/26 

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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

void solve(){
    int n;
    cin >> n;

    vector<ll> q(5), values;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;

        q[min(4, x)]++;
        if(x >= 4) values.PB(x);
    }

    ll ans = 0;
    if(q[4] == 0){
        ans = q[2] * 2 + q[3] * 3;
        ans = max(ans, (ll)(q[1] > 0) + 2 * (ll)(q[2] > 0));
        ans = max(ans, (ll)(q[1] > 0) + 3 * (ll)(q[3] > 0));
    }
    else if(q[4] == 1){
        ll spaces = values[0] / 2;
        
        ans = values[0] + q[2] * 2 + q[3] * 3 + min(spaces-1, q[1]);

        ans = max(ans, values[0] + min(spaces, q[1]));
    }
    else{
        ans = q[2] * 2 + q[3] * 3;
        ll spaces = 0;
        for(ll x: values){
            ans += x;
            spaces += x / 2 - 1;
        }
        ans += min(spaces, q[1]);
    }

    if(ans < 3) ans = 0;
    cout << ans << endl;
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
