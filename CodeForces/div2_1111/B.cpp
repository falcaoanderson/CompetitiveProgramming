/*
07/10/25 

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

int main(){
    fast_io;

    ll n, max_op, m;
    cin >> n >> max_op >> m;

    vector<int> v(n);
    
    for(int i=0; i<n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    ll sum=0;
    ll best_k = 1, best_top=0;

    for(int i=n-1; i>=0; i--){
        sum += (ll)v[i];

        if(i>m) continue;  
        
        ll k = n-i;
        ll top = sum+ min(m-n+k, max_op*k);

        if( top*best_k > k*best_top ){
            best_top = top;
            best_k = k;
        }
    }

    cout.precision(16);
    cout.setf(ios_base::fixed);

    cout << (double)(best_top) / (double)(best_k) << endl;
 
    return 0;
}
