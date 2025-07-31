/*
30/07/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

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

int main(){
    fast_io;
    int n, m, h;
    cin >> n >> h >> m;

    vector<int> l(m), r(m), x(m);
    for(int i=0; i<m; i++){
        cin >> l[i] >> r[i] >> x[i];
    }

    int resp = 0;

    for(int i=1; i<=n; i++){
        int crr = h;

        for(int j=0; j<=m; j++){
            if(l[j]<=i && i<=r[j]) crr = min(crr, x[j]);
        }

        resp += crr*crr;
    }

    cout << resp << endl;

    return 0;
}
