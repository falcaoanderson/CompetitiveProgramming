// 21/07/23 //
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
    
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<ll> memo = {0, 1};
    for(int i=2; i<n; i++) memo[i&1] = ( (ll)(i) * ((memo[i&1] + memo[~i&1])%MOD) )%MOD;

    cout << memo[~n&1] << endl;

    return 0;
}
