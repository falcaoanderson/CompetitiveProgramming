/*
29/03/26 

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

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

void solve(){
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    int ans = 0;
    ll aux;

    aux = gcd(a[0], a[1]);
    if(aux != a[0]){
        a[0] = aux;
        ans++;
    }
    for(int i = 1; i < n-1; i++){
        ll x = gcd(a[i-1], a[i]), y = gcd(a[i], a[i+1]);
        aux = (x * y) / gcd(x, y);

        if(aux < a[i]){
            ans++;
            a[i] = aux;
        }
    }
    aux = gcd(a[n-2], a[n-1]);
    if(aux != a[n-1]){
        a[n-1] = aux; 
        ans++;
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
