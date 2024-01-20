/*
19/01/24 
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

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n;
        ll f, a, b;
        cin >> n >> f >> a >> b;

        vector<ll> v(n+1);

        for(int i=1; i<=n; i++) cin >> v[i];
        
        for(int i=1; i<=n && f>0LL; i++){
            f -= min(a*(v[i]-v[i-1]), b);
        }

        cout << (f>0LL? "YES": "NO") << endl;
    }

    return 0;
}