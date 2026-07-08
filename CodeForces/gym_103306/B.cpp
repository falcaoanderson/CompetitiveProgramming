/*
12/04/26 

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
const int MAXN = (1e5) + 5;
const ll MOD  = 998244353;

ll fat[MAXN], ifat[MAXN];

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

ll bin(int a, int b){
    if((a < b) || (b < 0)) return 0LL;
    return (((fat[a] * ifat[b]) % MOD) * ifat[a-b]) % MOD;
}

void solve(){
    ll n, m;
    cin >> n >> m;

    ll k = m;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        k += a[i];
    }

    fat[0] = 1LL;
    for(int i=1; i<=m; i++) fat[i] = (fat[i-1] * (ll)i) % MOD;
    ifat[m] = exp(fat[m], MOD-2);
    for(int i=m-1; i>=0; i--) ifat[i] = (ifat[i+1] * (ll)(i+1)) % MOD;

    vector<ll> bdist(m+1);
    ll aux = exp(n, (MOD-2LL) * (ll)m); // (1 / n) ^ m
    for(int i=0; i<=m; i++){
        bdist[i] = (((bin(m, i) * aux) % MOD) * exp(n-1, m-i)) % MOD;
        if(i > 0) bdist[i] = (bdist[i-1] + bdist[i]) % MOD;
    }
    
    vector<ll> ans(10);
    for(ll d=1; d <= 9; d++){ // digitos
        for(int i=0; i < n; i++){ // baldes
            ll pot = 1;
            while(1){ // intervalos
                ll l = max(d * pot - a[i] - 1LL, -1LL);
                ll r = min((d + 1LL) * pot - 1LL - a[i], m);
                
                if(l >= m) break;

                if(l < r)
                ans[d] = (ans[d] + bdist[r] - (l==-1LL? 0LL: bdist[l]) + MOD) % MOD;
                
                pot *= 10LL;
            }
        }      
    }

    for(int i=1; i<=9; i++) cout << ans[i] << endl;
}

int main(){
    fast_io;

    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
