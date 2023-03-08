// 29/10/20 // 5:30 PM //

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

typedef pair<int, int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    vector<int> v(n+1);
    indexed_set subarray;

    for(int i=1; i<=n; i++){
        cin >> v[i];

        if(i<=k) subarray.insert(mp(v[i], i)); 
    }
    
    int meio = (k&1?k/2: k/2-1);
    auto  mediana = subarray.find_by_order(meio);
    cout << (mediana->first) << " ";
    
    for(int i=k+1; i<=n; i++){
        subarray.erase(mp(v[i-k], i-k));
        subarray.insert(mp(v[i], i));

        mediana = subarray.find_by_order(meio);
        cout << (mediana->first) << " ";
    }
    cout << endl;

    return 0;
}
