/*
31/08/25 

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

const ll MOD  = 998244353;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

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

    ll n, k;
    cin >> n >> k;

    vector<ll> b(n-k+1); 
    for(int i=0; i<n-k+1; i++){
        cin >> b[i];
    }

    ll lim=0;
    for(int i=0; i<min(k, n-k+1); i++){
        ll sum_c=0, min_sum_c=LINF;
        for(int j=i; j<n-k+1-1; j+=k){
            sum_c += b[j+1]-b[j];
            min_sum_c = min(min_sum_c, sum_c);
        }

        if(min_sum_c<0) lim -= min_sum_c;
    }

    if(lim>b[0]){
        cout << 0 << endl;
        return 0;
    }

    b[0] -= lim;

    ll x=1, y=1;
    for(ll i=b[0]+1LL; i<=b[0]+k-1LL; i++) 
        x = (x*i)%MOD;
    for(ll i=2; i<=k-1LL; i++)     
        y = (y*i)%MOD;

    cout << (x * exp(y, MOD-2LL))%MOD << endl;

    return 0;
}
