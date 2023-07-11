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

int main(){
    fast_io;

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> memo(n+1, -INF);
    memo[0] = 0;

    for(int i=1; i<=n; i++){
        if(i>=a){
            memo[i] = max(memo[i], memo[i-a] + 1);
        }
        if(i>=b){
            memo[i] = max(memo[i], memo[i-b] + 1);
        }
        if(i>=c){
            memo[i] = max(memo[i], memo[i-c] + 1);
        }
    }

    cout << memo[n] << endl;

    return 0;
}
