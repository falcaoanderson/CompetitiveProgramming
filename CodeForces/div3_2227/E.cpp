/*
30/04/26 

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

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    ll ans = 0;
    int crr_min = INF, crr_count = 0, max_count = 0;
    for(int i=n-1; i>=0; i--){
        if(v[i] < crr_min){
            crr_min = v[i];
            crr_count = 1;
        }
        else{
            crr_count++;
            max_count = max(max_count, crr_count);
        }

        ans += (ll)(v[i] - crr_min);
    }

    // cout << "ans, max_count := " << ans << " , " << max_count << endl;
    cout << ans + (ll)max(0, max_count - 1) << endl;
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
