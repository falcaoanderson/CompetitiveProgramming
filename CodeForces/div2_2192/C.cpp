/*
21/02/26 

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

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

void solve(){
    int n;
    ll h, k;
    cin >> n >> h >> k;

    multiset<ll> right;
    vector<ll> v(n);
    ll total = 0;
    cin >> v[0]; 
    total += v[0];
    for(int i=1; i<n; i++){
        cin >> v[i];

        total += v[i];
        right.insert(v[i]);
    }

    ll ans = (k + (ll)n) * (h / total);
    h %= total;

    if(h == 0){
        cout << ans - k << endl;
        return;
    }
    
    ll crr = v[0], min_left = v[0];
    for(int i=1; i<n; i++){
        if(crr >= h || crr + (*right.rbegin()) - min_left >= h){
            ans += (ll)(i);
            h = 0;
            break;
        }

        crr += v[i];
        if(min_left > v[i]){
            min_left = v[i];
        }
        right.erase(right.find(v[i]));
    }

    if(h > 0) ans += n;

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
