// 12/07/23 //
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
const int MAXN = (1e5);

ll freq[MAXN+5], memo[MAXN+5];

int main(){
    fast_io;

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        freq[val]++;
    }

    for(ll i=1; i<=MAXN; i++){
        memo[i] = max(memo[i-1], memo[i-2] + i*freq[i]);
    }

    cout << memo[MAXN] << endl;

    return 0;
}
