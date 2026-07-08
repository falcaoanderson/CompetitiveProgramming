/*
24/03/26 

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
const int MAXN = (3e5) + 5;
const ll MOD  = 998244353;

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

void solve(){
    int n;
    string s;

    cin >> n >> s;
    
    int sum = 0, count = 0;
    ll x = 0, y = 0, asterisco = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            sum++;
            x = (x + exp(2LL, i)) % MOD;
        }
        else{
            sum--;
            y = (y + (exp(2LL, count) * (1LL + asterisco)) % MOD) % MOD;
        }

        count++;
        if(sum <= 1){
            count = 0;
            asterisco = y;
        }
    }

    cout << (x + y) % MOD << endl;
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
