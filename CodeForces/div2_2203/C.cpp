/*
26/02/26 

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
    ll s, m;
    cin >> s >> m;

    vector<ll> v(64);
    vector<int> bits_m;
    for(int i=0; i<64; i++){
        if(((1LL<<i) & m) != 0){
            bits_m.PB(i);
        }
    }

    bool flag_ans = 1;
    for(int i=0; i<64 && flag_ans; i++){
        if(((1LL<<i) & s) != 0){
            flag_ans = 0;

            for(int j=SZ(bits_m) - 1; j>=0 && !flag_ans; j--){
                if(bits_m[j] <= i){
                    flag_ans = 1;
                    v[bits_m[j]] += (1LL<<(i-bits_m[j]));
                }
            }
        }
    }

    if(!flag_ans){
        cout << -1 << endl;
        return;
    }

    auto check_ans = [&bits_m](ll ans, vector<ll> v) -> bool {
        int idx = SZ(bits_m) - 1;

        for(int i=63; i>=0; i--){   
            if(v[i] > ans){
                while(idx >= 0 && bits_m[idx] >= i) idx--;
                if(idx < 0) return false;

                v[bits_m[idx]] += (v[i] - ans) * (1LL << (ll)(i - bits_m[idx])); 
            }
        }

        return true;
    };

    ll l = 1, r = 1e18, ans = -1;
    while(l <= r){
        ll mid = (l + r) / 2LL;
        if(check_ans(mid, v)){
            ans = mid;
            r = mid - 1LL;
        }
        else{
            l = mid + 1LL;
        }
    }
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
