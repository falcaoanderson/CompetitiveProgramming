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

int n, k;
ll a, b;
vector<int> v;

ll solve(int l, int r){
    auto it_lower = lower_bound(v.begin(), v.end(), l);
    auto it_upper = upper_bound(v.begin(), v.end(), r);

    // cout << l << " " << r << endl;

    if(it_lower == it_upper){ // esta vazio
        // cout << 0 << endl;
        // cout << a << endl;
        return a;
    }
    else{
        ll qnt = (it_upper - it_lower);
        // cout << qnt << endl;
        if(l==r){
            // cout << b * qnt * 1LL << endl; 
            return b * qnt * 1LL;
        }

        int mid = (l+r)/2;
        // cout << 'x' << endl;
        return min(b * qnt * (ll)(r-l+1), solve(l, mid) + solve(mid+1, r));
        
    }
}

int main(){
    fast_io;

    cin >> n >> k >> a >> b;
    
    v.assign(k, 0);
    for(int i=0; i<k; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cout << solve(1, (1<<n)) << endl;
 
    return 0;
}
