// 18/11/20 // 8:18 PM //

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

// less_equal<int> para multiset
typedef pair<int, int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

indexed_set v;

int main(){
    fast_io;
    
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int val;
        cin >> val;

        v.insert({i, val});
    }

    for(int i=1; i<=n; i++){
        int pos;
        cin >> pos;

        auto x = v.find_by_order(pos-1);

        cout << (x->second) << " ";
        v.erase(x);
    }
    cout << endl;

    return 0;
}
