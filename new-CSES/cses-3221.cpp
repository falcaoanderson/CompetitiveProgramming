/*
04/03/26 

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

int main(){
    fast_io;

    int n, k;
    ll x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    ll ans = 0;
    for(int i=1; i<=n; i++){
        int l = max(1, k - (n - i));
        int r = min(k, i);

        if((r-l+1) & 1){
            ans ^= x;
        }

        x = ((x * a)%c + b)%c;
    }

    cout << ans << endl;

    return 0;
}
