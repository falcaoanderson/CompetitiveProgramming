// 13/06/23 // O(q*log(n))
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

    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i=0; i<n; i++) cin >> prices[i];

    sort(prices.begin(), prices.end());

    int q;
    cin >> q;

    while(q--){
        int val;
        cin >> val;

        auto it = upper_bound(prices.begin(), prices.end(), val);

        cout << it-prices.begin() << endl;
    }

    return 0;
}