/*
06/08/25 

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

ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    fast_io;

    ll n, k, a, b;
    cin >> n >> k;
    cin >> a >> b;

    ll x = LINF, y=-LINF; 
    vector<ll> v = {(b-a+k)%k, (k-a-b)%k, (a+b)%k, (a-b+k)%k};

    for(int i=0; i<4; i++){
        for(ll j=0; j<n; j++){
            ll l = k*j + v[i];
        
            ll crr = (n*k) / gcd(n*k, l);

            x = min(x, crr);
            y = max(y, crr);
        }
    }
    cout << x << " " << y << endl;

    return 0;
}
