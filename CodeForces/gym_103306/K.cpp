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
const int MAXN = (1e6) + 5;
const int MOD  = (1e9) + 7;

int sieve[MAXN];

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

vector<int> find_primes(int x){
    vector<int> primes;

    while(x > 1){
        int p = sieve[x];
        while((x % p) == 0){
            x /= p;
        }
        primes.PB(p);
    }

    return primes;
}

int gcd(int a, int b){
    return (b==0? a: gcd(b, a % b));
}

void solve(){
    int k;
    cin >> k;

    if(k==1){
        cout << 0 << endl;
        return;
    }

    auto primes = find_primes(k);
    int qnt_primes = SZ(primes);

    ll ans = 0;
    for(int mask = 1; mask < (1<<qnt_primes); mask++){
        int sz = 0, val = 0;
        for(int i = 0; i < qnt_primes; i++){
            if((1<<i) & mask){
                sz++;
                val = gcd(val, k / primes[i]);
            }
        }

        ans = (ans + exp(2, val) * (sz&1 ? 1LL: -1LL) + MOD) % MOD; 
    }
    cout << ans << endl;
}

int main(){
    fast_io;

    for(int i=2; i<=MAXN-5; i++){
        if(sieve[i] == 0){
            for(int j=i; j<=MAXN-5; j+=i){
                sieve[j] = i;
            }
        }
    }

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
