// 29/04/23 //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

// less_equal<int> para multiset
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

indexed_set v;

void del(int a){ // para apagar do multiset
    v.erase(v.find_by_order(v.order_of_key(a)));
}

int main(){
    fast_io;
    
    int n, k;
    cin >> n >> k;
    
    vector<int> num(n);
    
    for(int i=0; i<n; i++) cin >> num[i];
    
    for(int i=0; i<k; i++) v.insert(num[i]);
    
    int med=(k-1)/2;
    cout << *v.find_by_order(med) << " ";
    
    for(int i=k; i<n; i++){
        del(num[i-k]);
        v.insert(num[i]);
        
        cout << *v.find_by_order(med) << " ";
    }
    cout << endl;
    
    return 0;
}
