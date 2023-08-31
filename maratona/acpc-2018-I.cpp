#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstdio>
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

void solve(){
    int n, k;
    cin >> n >> k;

    vector<pii> v(n);
    for(int i=0; i<n; i++) cin >> v[i].ff;
    for(int i=0; i<n; i++) cin >> v[i].ss;
    sort(v.begin(), v.end());

    int cal = v[k-1].ff;
    vector<int> h;

    for(int i=0; i<n && v[i].ff<=cal; i++){
        h.PB(v[i].ss);
    }
    
    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());

    ll hapiness=0LL;
    for(int i=0; i<k; i++){
        hapiness += (ll)h[i];
    }

    cout << cal << " " << hapiness << endl;
}

int main(){
    freopen("icecream.in", "r", stdin);
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}