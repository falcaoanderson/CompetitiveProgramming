// 05/08/23 // dp // O(t*n) //
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

const int MAXT = 50 + 5;
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int memo[MAXT][MAXN];

int main(){
    fast_io;

    int t, m, n;
    cin >> t >> m >> n;

    for(int i=m; i<=n; i++) memo[1][i] = 1;

    for(int i=2; i<=t; i++){
        memo[i][m] = memo[i-1][m+1]; 
        memo[i][n] = memo[i-1][n-1];

        for(int j=m+1; j<=n-1; j++){
            memo[i][j] = (memo[i-1][j-1] + memo[i-1][j+1])%MOD;
        }
    }

    int resp = 0;
    for(int i=m; i<=n; i++) resp = (resp + memo[t][i])%MOD;

    cout << resp << endl;

    return 0;
}
