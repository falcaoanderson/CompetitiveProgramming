/*
23/10/25 

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
const int MAXN = (1e6) + 5;
const int MOD  = (1e9) + 7;

bool cmp(pii a, pii b){
    return a.FF+a.SS < b.FF+b.SS;
}

void solve(){
    int n;
    cin >> n;
    
    vector<pii> v; 
    ll resp = 0;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        resp += (ll)(b-a);
        
        v.PB({a, b});
    }

    sort(v.begin(), v.end(), cmp);
    
    int l = 0, r = n-1;
    while(l<r){
        resp += ll(v[r].SS - v[l].FF);
        l++;
        r--;
    }

    if(n&1){
        ll auxresp = resp;

        for(int i=0; i<l; i++){
            auxresp = max(auxresp, resp + (ll)(v[i].FF - v[l].FF));
        }
        for(int i=l+1; i<n; i++){
            auxresp = max(auxresp, resp + (ll)(v[l].SS - v[i].SS));
        }

        resp = auxresp;
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
