/*
04/01/25 
CF 577 Div.2 A
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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;
    
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll mid=n/2, resp = v[n/2];
    for(ll i=n/2+1; i<n; i++){
        if((v[i]-resp)*(i-mid)<=k){
            k -= (v[i]-resp)*(i-mid);
            resp = v[i];
        }
        else{
            resp += k/(i-mid);
            k = 0;
            break;
        }
    }
    resp += k/(n-mid);

    cout << resp << endl;

    return 0;
}
