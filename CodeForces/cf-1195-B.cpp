/*
14/07/25 

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

    ll n, k, b, c;
    cin >> n >> k;

    b = -4 -2*n;
    c = n*n-2*k+2*n+1;

    ll s1 = (-b + (ll)sqrtl(b*b-4*c))/2LL;
    ll s2 = (-b - (ll)sqrtl(b*b-4*c))/2LL;

    if(s1>=0 && s1<=n && (((-b) + (ll)sqrtl(b*b-4*c))%2LL==0LL)) cout << s1 << endl;
    else cout << s2 << endl;

    return 0;
}
