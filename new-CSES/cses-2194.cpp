// 21/09/23 //
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
#include <functional>
#include <cmath>
using namespace std;
 
#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll qmod(pll a, pll b){
    return (a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss);
}

int main(){
    fast_io;
 
    int n;
    cin >> n;
 
    vector<pll> point(n);
 
    for(int i=0; i<n; i++){
        cin >> point[i].ff >> point[i].ss;
    }
 
    sort(point.begin(), point.end());
 
    set<pll> window;
    ll qdist = qmod(point[0], point[1]);
    int l=0;

    for(int i=0; i<n; i++){
        ll dist = ceil(sqrt((double)qdist));

        while(l<i && point[i].ff - point[l].ff >= dist){
            window.erase({point[l].ss, point[l].ff});
            l++;
        }

        auto it = window.upper_bound( {point[i].ss - dist, -LINF} );

        for(;it!=window.end() && (it->first) < point[i].ss + dist; it++){
            qdist = min(qdist, qmod(point[i], {it->second, it->first}));
        }
 
        window.emplace(point[i].ss, point[i].ff);
    }
 
    cout << qdist << endl;
 
    return 0;
}