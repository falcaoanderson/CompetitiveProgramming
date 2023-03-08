// 16/11/20 // 4:45 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

const ll MOD  = (1e9) + 7;
const ll INV2 = 500000004LL;

ll sum(ll a, ll b){
    
    ll x = a+b;
    ll y = b-a+1LL;
    
    if(x%2==0) x /= 2;
    else       y /= 2;
    
    x %= MOD; y %= MOD;

    return (x*y)%MOD;
}

int main(){
    fast_io;

    ll n;
    cin >> n;

    ll resp = 0LL;

    for(ll i=1LL; i*i<=n; i++){
        resp += ((n/i) * i)%MOD;
        resp %= MOD;
        
        if(n/(i+1LL)<i) continue;

        resp += (sum(n/(i+1LL) + 1LL, n/i)*i)%MOD;
        resp %= MOD;
    }

    /*/solve O(n)
    ll respb = 0LL;
    for(ll i=1LL; i<=n; i++){
        respb += ((n/i)*i)%MOD;
        respb %= MOD;
    }
    cout <<respb << endl;
    */  

    cout << resp << endl;
    

    return 0;
}
