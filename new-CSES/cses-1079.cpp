// 22/04/23 // teoria dos numeros // combinatoria
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

const ll MOD = 1e9+7;
const int MAXN = 1e6+5;

ll fact[MAXN];
ll inv_fact[MAXN];

ll expo(ll a, ll b, ll mod=MOD){
    if(b==0LL) return 1LL;
    
    if(b&1LL){
        return (a*expo(a, b-1LL, mod))%mod;
    }
    
    return expo((a*a)%mod, b/2LL, mod)%mod;
}

void init_factorial(int n){
    fact[0] = 1;

    for(ll i=1; i<=n; i++){
        fact[i] = (i * fact[i-1])%MOD;
    }
}
void init_inv_fact(int n){
    vector<ll> prefix(n+1);
    prefix[0] = fact[0];
    for(int i=1; i<=n; i++){
        prefix[i] = ((ll)fact[i] * prefix[i-1])%MOD;
    }
    
    ll sufix = 1;
    inv_fact[0] = 1;
    ll inv = expo(prefix[n], MOD-2LL, MOD);

    for(int i=n; i>=1LL; i--){
        inv_fact[i] = ((prefix[i-1] * sufix)%MOD * inv)%MOD;

        sufix = (fact[i]*sufix)%MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init_factorial(1e6);
    init_inv_fact(1e6);

    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;

        cout << (((fact[a] * inv_fact[b])%MOD) * inv_fact[a-b])%MOD << endl;
    }
    
    return 0;
}