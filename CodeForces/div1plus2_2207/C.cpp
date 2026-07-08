/*
08/03/26 

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
    int n, h;
    cin >> n >> h;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<ll> total(n);

    for(int i=0; i<n; i++){
        int crr_max = 0;
        for(int j=i; j<n; j++){
            crr_max = max(crr_max, a[j]);
            total[i] += (ll)(h - crr_max);
        }
        crr_max = a[i];
        for(int j=i-1; j>=0; j--){
            crr_max = max(crr_max, a[j]);
            total[i] += (ll)(h - crr_max);
        }
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, total[i]);
        
        int idx = i, max_a = a[i];
        
        for(int j=i+1; j<n; j++){
            if(a[j] > max_a){
                idx = j;
                max_a = a[j];
            }

            ans = max(ans, total[i] + total[j] - total[idx]);
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
