// terminar depois //
// 11/04/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MOD = 1e9+7;

inline ll max(ll a, ll b){
    return (a>b? a: b);
}
inline ll min(ll a, ll b){
    return (a<b? a: b);
}
/*
int solve(int i, int val){
    if(val==0){
        return 0;
    }
    if(i==0) return INF;

    return min(solve(i-1, val), 1 + solve(i-1, val-coin[i]));
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    vector<int> coins(n);

    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    //memo[i][val]
    vector< vector<int> > memo(n+1, vector<int>(x+1, 0));
    for(int j=1; j<=x; j++){
        memo[0][j] = n+1;
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=x; j++){
            if(j>=coins[i])
                memo[i][j] = min(memo[i-1][j], memo[i-1][j-coins[i]] + 1);
            else
                memo[i][j] = memo[i-1][j];
        }
    }

    cout << memo[n][x] << endl;

    return 0;
}
