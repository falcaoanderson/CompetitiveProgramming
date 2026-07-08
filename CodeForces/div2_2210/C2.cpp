/*
10/04/26 

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

vector<ll> primes = {2};
vector<ll> find_prime(ll x, ll y, ll lim){
    vector<ll> v;
    for(ll p: primes){
        if(p * y > lim || SZ(v) == 20) break;
        if((x % p) != 0) v.PB(p);
    }
    return v;
}

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

void solve(){
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    vector<ll> new_a(n);
    int ans = 0;

    for(int i=0; i<n; i++){
        ll x = 1, y = a[i], z = 1;
        if(i > 0)   x = a[i-1];
        if(i < n-1) z = a[i+1];

        ll xy = gcd(x, y), yz = gcd(y, z);
        ll aux = (xy * yz) / gcd(xy, yz);

        if(aux < a[i] && aux <= b[i]){
            new_a[i] = aux;
            ans++;
        }
        else{
            new_a[i] = a[i];
        }
    }

    vector<pair<int, ll>> options = {{0, 1}};
    for(int i=0; i<n; i++){
        vector<pair<int, ll>> new_options;
        vector<ll> vp;

        if(new_a[i] == a[i] && a[i] < b[i]){
            ll x = 1, y = new_a[i], z = 1;
            if(i > 0)   x = new_a[i-1];
            if(i < n-1) z = new_a[i+1];

            x /= gcd(x, y);
            z /= gcd(y, z);
            ll xz = (x * z) / gcd(x, z);
            vp = find_prime(xz, y, b[i]);
        }
        vp.PB(1);
        
        int aux = 0;
        for(ll crr_p: vp){
            aux = 0;
            for(auto qnt_x: options){
                int qnt = qnt_x.FF; 
                ll x = qnt_x.SS;

                if(gcd(x, new_a[i] * crr_p) == gcd(i>0?new_a[i-1]:1LL, new_a[i])){
                    aux = max(aux, qnt + (int)(crr_p != 1LL));
                }
            }
            new_options.PB({aux, new_a[i] * crr_p});
        }
        
        swap(options, new_options);
    }

    int aux = 0;    
    for(auto qnt_p: options){
        aux = max(aux, qnt_p.FF);
    }

    cout << ans + aux << endl;
}

int main(){
    fast_io;

    for(int i=3; i<=1000 && SZ(primes) <= 100; i+=2){
        bool flag = 1;
        for(int j=2; j*j <= i && !flag; j++){
            if((i % j) == 0) flag = 1;
        }
        if(flag){
            primes.PB(i);
        }
    }

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
