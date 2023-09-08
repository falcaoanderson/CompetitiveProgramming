// 01/09/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

void solve(){
    int n, m;
    ll d;

    cin >> n >> m >> d;

    multiset<ll> crr;
    ll resp = 0, crr_sum = 0;

    for(ll i=1; i<=n; i++){
        ll val;
        cin >> val;

        if(val>0){
            if((int)crr.size()<m){
                crr_sum += val;
                crr.insert(val);
            }
            else if((*crr.begin()) < val){
                crr_sum += val - (*crr.begin());
                crr.erase(crr.begin());
                crr.insert(val);
            }
        }

        resp = max(resp, crr_sum - i*d);
    }

    cout << resp << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
