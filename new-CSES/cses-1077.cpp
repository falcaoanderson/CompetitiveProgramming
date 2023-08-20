// 20/08/23 //

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

indexed_set iset;

void apagar(int a){ // para apagar do multiset
    iset.erase(iset.find_by_order(iset.order_of_key(a)));
}

ll mod(int a){
    return (a<0? -a: a);    
}


int main(){
    //fast_io;
    
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    for(int i=0; i<k; i++) iset.insert(v[i]);    
    
    int imed = (k-1)/2;
    int med = *iset.find_by_order(imed);
    
    ll resp = 0;
    for(int i=0; i<k; i++) resp += mod(med-v[i]);

    cout << resp << " ";
    for(int i=k; i<n; i++){
        apagar(v[i-k]);
        iset.insert(v[i]);
        
        int new_med = *iset.find_by_order(imed); 
        
        resp += mod(new_med - v[i]) - mod(med - v[i-k]) + (k&1? 0LL: med-new_med);
        
        med = new_med;
        
        cout << resp << " ";
    }
    cout << endl;
    
    return 0;
}
