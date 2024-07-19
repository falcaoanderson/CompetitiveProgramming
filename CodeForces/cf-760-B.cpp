// 25/04/24 //
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    ll n, m, k;
    cin >> n >> m >> k;

    m -= n;

    ll l=0, r=m, mid, resp=1;

    while(l<=r){
        mid = (l+r)/2LL;

        ll fr = min(mid-1, n-k), fl= min(mid-1, k-1);
        fr = max(fr, 0LL);
        fl = max(fl, 0LL);

        ll total = mid + mid*(fl + fr) - (fr*(fr+1LL))/2LL - (fl*(fl+1LL))/2LL;

        if(total<=m){
            resp = mid+1LL;
            l = mid+1LL;
        }
        else{
            r = mid-1LL;
        }
    }

    cout << resp << endl;

    return 0;
}
