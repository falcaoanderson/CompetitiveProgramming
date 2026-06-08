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

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());

    int aux = 0;
    for(int i=0; i<k; i++){
        aux = max(aux, v[i]);
    }
    ll sum = 0;
    for(int i=k; i<n; i++){
        sum += v[i];
    }

    cout << max(sum, (ll)aux) << endl;
}
int main(){
    fast_io;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}