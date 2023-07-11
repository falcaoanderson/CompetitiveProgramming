// 11/07/23 //
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

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e3) + 5;
const ll MOD  = 998244353LL;

ll memo[MAXN][MAXN];

int main(){
    fast_io;

    int n, m, k;
    cin >> n >> m >> k;

    memo[1][0] = m;
    memo[1][1] = 0LL;

    for(int i=2; i<=n; i++){
        memo[i][0] = memo[i-1][0];

        for(int j=1; j<=min(k, i); j++){
            memo[i][j] = ((memo[i-1][j-1]*((ll)(m-1LL)))%MOD + memo[i-1][j])%MOD;
        }
    }

    cout << memo[n][k] << endl;

    return 0;
}
