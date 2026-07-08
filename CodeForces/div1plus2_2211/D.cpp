/*
01/04/26 

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
const ll MOD   = (1e9) + 7;

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

ll comb(ll a, ll b){
    if(b > a || b < 0) return 0LL;
    if(b == 0) return 1;
    
    return ((fat[a] * ifat[b]) % MOD * ifat[a-b]) % MOD;
}

void solve(){
    int n;
    cin >> n;
     
    vector<ll> b(n+2), z(n+2), q(32);
    
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }

    for(int i=n; i>=1; i--){
        z[i] = b[i];
        for(int k=0; k<29; k++){
            if(q[k] != 0){
                z[i] = (z[i] + MOD - ((ll)(1 << k) * comb(q[k], i)) % MOD) % MOD;
            }
        }
        
        for(int k=0; k<29; k++){
            if((z[i]&(1<<k)) != 0){
                q[k] = i;
            }
        }
        z[i] += z[i+1];
    }

    for(int i=n; i>=1; i--) 
        cout << z[i] << " ";
    cout << endl;
}

int main(){
    fast_io;

    int n = 1e5;
    fat[0] = 1;
    for(int i=1; i<=n; i++) fat[i] = ((ll)i * fat[i-1]) % MOD;
    ifat[n] = exp(fat[n], MOD-2);
    for(int i=n-1; i>=0; i--){
        ifat[i] = ((ll)(i+1) * ifat[i+1]) % MOD; 
    }

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
