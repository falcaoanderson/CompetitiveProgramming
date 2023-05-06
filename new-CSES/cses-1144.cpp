// 06/05/23 //
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
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

indexed_set v;

void apagar(int a){ // para apagar do multiset
    v.erase(v.find_by_order(v.order_of_key(a)));
}

int main(){
    fast_io;
    
    int n, q;
    cin >> n >> q;
    
    vector<int> salary(n+1);
    for(int i=1; i<=n; i++){
        cin >> salary[i];
        v.insert(salary[i]);
    }
    
    while(q--){
        char op; int a, b;
        cin >> op >> a >> b;
        
        if(op=='!'){
            apagar(salary[a]);
            salary[a] = b;
            v.insert(salary[a]);
        }
        else{
            int ini = v.order_of_key(a);
            int fim = v.order_of_key(b+1);
            
            cout << fim-ini << endl;
        }
    }

    return 0;
}
