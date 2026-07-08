/*
29/04/26 

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

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    int max_odd = 0, max_even = 0, min_odd = INF, min_even = INF; 
    for(int i=0; i<n; i++){
        cin >> v[i];

        if(v[i] & 1){
            max_odd = max(max_odd, v[i]);
            min_odd = min(min_odd, v[i]);
        }
        else{
            max_even = max(max_even, v[i]);
            min_even = min(min_even, v[i]);
        }
    }

    bool ans = 1;
    int crr_max_odd = 0, crr_max_even=0;
    for(int i=0; i<n; i++){
        if(v[i] & 1){
            if(v[i] < crr_max_odd && max_even < crr_max_odd && min_even > v[i]){
                ans = 0;
                break;
            }

            crr_max_odd = max(crr_max_odd, v[i]);
        }
        else{
            if(v[i] < crr_max_even && max_odd < crr_max_even && min_odd > v[i]){
                ans = 0;
                break;
            }

            crr_max_even = max(crr_max_even, v[i]);
        }
    }

    cout << (ans? "YES": "NO") << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}