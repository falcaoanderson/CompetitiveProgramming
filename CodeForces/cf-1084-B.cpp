/*
19/08/25 

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

    int n; ll glass;
    cin >> n >> glass;

    vector<ll> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll l=0, r=1e9, resp = -1;
    while(l<=r){
        ll mid = (l+r)/2, total = 0, crr=mid;
        
        for(int i=0; i<n; i++){
            if(v[i]>mid){
                total += v[i]-mid;
            }
            crr = min(crr, v[i]);
        }

        if(total>=glass){
            resp = crr;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout << resp << endl;

    return 0;
}
