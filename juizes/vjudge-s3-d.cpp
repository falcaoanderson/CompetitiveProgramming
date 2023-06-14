// 13/06/23 //
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

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    vector<ll> prefix(n+1, 0LL);

    for(int i=1; i<=n; i++){
        ll val;
        cin >> val;

        prefix[i] = prefix[i-1] + val;
    }

    while(m--){
        ll val;
        cin >> val;

        auto it = lower_bound(prefix.begin(), prefix.end(), val);

        int pos = it-prefix.begin();

        cout << pos << " " << val-prefix[pos-1] << endl;
    }

    return 0;
}
