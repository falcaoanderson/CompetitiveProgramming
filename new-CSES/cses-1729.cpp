// 10/08/23 //
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
const int MAXN = (1e6) + 5;
 
int memo[MAXN][5];
 
int main(){
    fast_io;
 
    int n, k;
    cin >> n >> k;
 
    vector<int> v(k);
    for(int i=0; i<k; i++) cin >> v[i];
 
    sort(v.begin(), v.end());
 
    memo[0][0] = 1;
    memo[0][1] = 0;
 
    for(int i=1; i<=n; i++){
        memo[i][0] = INF;
        memo[i][1] = -INF;
 
        for(int j=0; j<k && v[j]<=i; j++){
            memo[i][0] = min(memo[i][0], memo[i-v[j]][1]);
            memo[i][1] = max(memo[i][1], memo[i-v[j]][0]);
 
            if(memo[i][0]==0 && memo[i][1]==1) break;
        }   
    }
 
    for(int i=1; i<=n; i++){
        cout << (memo[i][0]==0? "W": "L"); 
    }
    cout << endl;
 
    return 0;
}