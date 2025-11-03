/*
23/10/25 

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
const ll MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

int main(){
    fast_io;

    int n, q;
    cin >> n >> q;
    
    string s;
    cin >> s;

    vector<int> prefix(n+1);
    for(int i=1; i<=n; i++){
        prefix[i] = prefix[i-1] + (int)(s[i-1]=='1');
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        ll a = prefix[r] - prefix[l-1];
        ll b = (ll)(r-l+1) - a;

        // cout << "query: " << endl;
        // cout << a << " " << b << endl;

        cout << (exp(2, b) * ((exp(2, a) - 1LL + MOD) % MOD)) % MOD << endl;
    }

    return 0;
}
