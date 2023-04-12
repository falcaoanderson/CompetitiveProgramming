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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> memo(n+1);
    memo[0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=6 && j<=i; j++){
            memo[i] = (memo[i] + memo[i-j])%MOD;
        }
    }

    cout << memo[n] << endl;

    return 0;
}
