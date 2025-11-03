/*
21/10/25 

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

int solve(int h, int d){
    int l=0, r=1e9, mid, resp=0;

    while(l<=r){
        mid = (l+r)/2;

        ll q = d / (mid+1), res = d % (mid+1);
        ll a = mid + 1 - res;

        ll custo = a * ((q * (q+1LL)) / 2LL) + res * (((q+1LL) * (q+2LL)) / 2LL);

        if(custo < (ll)(h + mid)){
            resp = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    return (d + resp);
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int h, d;
        cin >> h >> d;

        cout << solve(h, d) << endl;
    }

    return 0;
}
