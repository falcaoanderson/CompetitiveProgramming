/*
31/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<ll> a(n+1), b(3);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        ll x;
        cin >> x;
        b[i%3] += x;
    }

    vector<ll> ans(3);
    for(int i=1; i<=n; i++){
        ans[0] += a[i] * b[(3 - i%3) % 3];
        ans[1] += a[i] * b[(4 - i%3) % 3];
        ans[2] += a[i] * b[(5 - i%3) % 3];
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;

    return 0;
}