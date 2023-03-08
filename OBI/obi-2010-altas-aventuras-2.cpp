// 27/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int LOGMAXN = 32;
const int MOD  = (1e9) + 7;

ll n, k;

ll sum_comb(ll q){
    ll atual = 1LL, resp=0LL;

    for(ll i=1; i<=k && resp<n; i++){
        atual *= (q-i+1LL);
        atual /= i;
       
        resp += atual;
    }
    
    return resp;
} 

int main(){
    fast_io;

    cin >> n >> k;

    if(k==1LL){
        cout << n << endl;
        return 0;
    }

    ll l=1LL, r=n, mid, resp=0LL;

    while(l<=r){
        mid = (l+r)/2LL;

        if(sum_comb(mid)>=n){
            resp = mid;
            r = mid-1LL;
        }
        else
            l = mid+1LL;
    }

    cout << resp << endl;

    return 0;
}
