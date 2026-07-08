/*
28/03/26 

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
    int x, y;
    cin >> x >> y;

    if(x == 0 || y == 0){
        int a = max(x, y);

        int q = 0;
        for(int i=1; i<=a; i++){
            if((a % i) == 0) q++;
        }
        cout << q << endl;
    }
    else if(x == y){
        cout << 1 << endl;
    }
    else{
        int a = max(x, y);
        int b = min(x, y);
        int q = 0;
        for(int k = b+1; k <= a; k++){
            if(((a - k) % (k - b)) == 0) q++;
        }
        cout << q << endl;
    }

    while(x--) cout << 1 << " ";
    while(y--) cout << -1 << " ";
    cout << endl;
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
