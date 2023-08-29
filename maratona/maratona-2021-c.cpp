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
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

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
     
    ll b, n;
    cin >> b >> n;

    vector<ll> digit(n+1);
    ll k = 0LL;
    ll mod = b+1LL;
    
    for(int i=1; i<=n; i++){
        cin >> digit[i];

        k = (k + (digit[i] * exp(b, n-i, b+1))%mod)%mod;
    }

    if(k==0){
        cout << "0 0" << endl;
        return 0;
    }

    ll inv_b = exp(b, phi(b+1)-1, mod);

    for(int i=1; i<=n; i++){
        ll d = (k * exp(inv_b, n-i, mod))%mod;

        if(d<=digit[i]){
            cout << i << " " << digit[i]-d << endl;
            return 0;
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}
