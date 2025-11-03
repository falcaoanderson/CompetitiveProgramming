/*
30/10/25 

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
    int r, x, d, n;
    cin >> r >> x >> d >> n;

    string v;
    cin >> v;

    int resp = 0;
    for(char c: v){
        if(c=='1' || (c=='2' && r<x)){
            resp++;
            r = max(r-d, 0);
        }
    }
    
    cout << resp << endl;
}

int main(){
    fast_io;
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
