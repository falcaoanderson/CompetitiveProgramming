/*
08/08/24 
Problem: 
Complexity:
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

    int t;
    cin >> t;

    for(int z=1; z<=t; z++){
        ll n, m, k, resp = 0;
        cin >> n >> m >> k;

        for(int i=0; i<k; i++) 
            resp = ( resp + ( exp(i, m+n-2LL) * exp(k, (n-1LL)*(m-1LL)) )%MOD )%MOD;
        
        resp = ((resp * n *m)%MOD + exp(k, n*m))%MOD;


        cout << "Case #" << z << ": " << resp << endl;
    }

    return 0;
}
