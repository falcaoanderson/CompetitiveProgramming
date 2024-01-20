/*
20/01/24 
Problem: 
Complexity:
*/

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
#define FF first
#define SS second

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

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<ll> a(n), v(m);

        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> v[i];

        sort(v.begin(), v.end());
        sort(a.begin(), a.end());

        int la=0, ra=n-1, lv=0, rv=m-1;
        ll resp = 0LL;

        while(la<=ra){
            if(abs(a[la]-v[rv]) > abs(a[ra]-v[lv])){
                resp += (ll)abs(a[la]-v[rv]);
                la++;
                rv--;
            }
            else{
                resp += (ll)abs(a[ra]-v[lv]);
                ra--;
                lv++;
            }
        }
        cout << resp << endl;
    }

    return 0;
}
