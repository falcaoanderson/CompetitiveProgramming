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

    ll ans = 0, w = 0, xold = x;
    for(int i=1; i<=k; i++){
        w += x;
        x = (a * x + b) % c;
    }
    ans = w;
    for(int i=2; i<=n-k+1; i++){
        w += x - xold;
        x = ((a * x) % c + b) % c;
        xold = ((a * xold) % c + b) % c;
        ans ^= w;
    }

    cout << ans << endl;

    return 0;
}
