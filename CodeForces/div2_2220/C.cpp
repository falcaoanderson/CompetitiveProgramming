/*
13/04/26 

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
    int p, q;
    cin >> p >> q;

    int x = -1, y = -1;
    for(int n=1; n<15000; n++){
        int m;
        if(((p + 2 * q - n) % (2*n + 1)) == 0){
            m = (p + 2 * q - n) / (2*n + 1);
        }
        else continue;
        if(m < n) continue;

        int a = p - (m - n), b = m * n + n - q; 
        if(a == 2 * b && a >= 0){
            x = n;
            y = m;
            break;
        }
    }

    if(x==-1){
        cout << -1 << endl;
    }
    else{
        cout << x << " " << y << endl;
    }
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
