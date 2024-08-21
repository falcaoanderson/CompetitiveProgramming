/*
21/08/24 
Problem: 
Complexity:
*/

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

    ll n, resp=0;
    cin >> n;

    // for(ll i=1; i<=n; i++){
    //     resp += (i%MOD * ((n/i)%MOD))%MOD;
    //     resp %= MOD;
    // }
    // cout << resp << endl;
    // resp = 0;

    for(ll i=1; i<=n; i++){
        ll k = n/i;
        ll q = (n-k*i)/k;

        resp += ((k%MOD) * ((((i%MOD)*((q+1LL)%MOD))%MOD + (q&1? (((q+1)/2LL)%MOD) * (q%MOD): ((q/2LL)%MOD)*((q+1)%MOD))%MOD)%MOD))%MOD;
        resp %= MOD;

        i+=q;
    }
    
    cout << resp << endl;

    return 0;
}
