/*
06/05/26 

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

int query(vector<int>& bit, int i){
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & (-i));
    }
    return sum;
}
void update(vector<int>& bit, int i, int delta){
    while(i < SZ(bit)){
        bit[i] += delta;
        i += (i & (-i));
    }
}

void solve(){
    int n;
    cin >> n;

    vector<ll> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    vector<pair<ll, int>> vaux = {{0, 0}};
    for(int i=1; i<=n; i++){
        if(i & 1){
            v[i] = v[i-1] + v[i];
        }
        else{
            v[i] = v[i-1] - v[i];
        }

        vaux.PB({v[i], i});
    }

    sort(vaux.begin(), vaux.end());
    ll maxval = 1;
    for(int i=0; i<=n; i++){
        if(i > 0 && vaux[i].FF > vaux[i-1].FF) maxval++;
        v[vaux[i].SS] = maxval;
    }

    ll ans = 0;
    vector<int> bit_even(maxval+1), bit_odd(maxval+1);
    for(int i=0; i<=n; i++){
        if(i & 1){
            ans += (ll) query(bit_even, v[i] - 1);
            update(bit_odd, v[i], 1);
        }
        else{
            ans += (ll) (i / 2 - query(bit_odd, v[i]));
            update(bit_even, v[i], 1);
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
