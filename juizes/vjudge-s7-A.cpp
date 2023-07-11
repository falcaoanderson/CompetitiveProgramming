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
const int MAXN = 1e2+5;
const int MAXV = 1e4;

int memo[MAXN][MAXV+5];

void solve(){
    int value, n;
    cin >> value >> n;

    vector<int> coin(n+1);
    for(int i=1; i<=n; i++) cin >> coin[i];

    memo[0][0] = 0;
    for(int j=1; j<=MAXV; j++) memo[0][j] = INF;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=MAXV; j++){
            memo[i][j] = memo[i-1][j];

            if(coin[i]<=j) memo[i][j] = min(memo[i][j], memo[i-1][j-coin[i]] + 1);
        }
    }

    for(int j=value ; j<=MAXV; j++){
        if(memo[n][j]!=INF){
            cout << j << " " << memo[n][j] << endl;
            break;
        }
    }
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}