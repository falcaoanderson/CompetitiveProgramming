// 01/07/23 //
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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, p;
    cin >> n >> p;
    
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    vector<int> memo(n+1);
    int resp=0;

    for(int i=1; i<=n; i++){
        memo[i] = max(memo[i-1] + v[i]-p, v[i]-p);

        resp = max(resp, memo[i]);
    }

    cout << resp << endl;

    return 0;
}
