// 29/04/23 //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"

typedef tuple<int, int, int> tiii;

// less_equal<int> para multiset
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

indexed_set finais;

// para apagar do multiset
void apagar(int a){
    finais.erase(finais.find_by_order(finais.order_of_key(a)));
}

bool comp(tiii a, tiii b){
    if(get<0>(a) == get<0>(b)) return ( get<1>(a)>get<1>(b) );
    return ( get<0>(a) < get<0>(b) );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<tiii> v(n);
    
    for(int i=0; i<n; i++){
        cin >> get<0>(v[i]) >> get<1>(v[i]);

        get<2>(v[i]) = i;  
    }
    sort(v.begin(), v.end(), comp);
    
    vector<int> contains(n), belongs(n);

    for(int i=0; i<n; i++) finais.insert(get<1>(v[i]));

    for(int i=0; i<n-1; i++){
        int a, b, ind;
        tie(a, b, ind) = v[i];

        apagar(b);

        contains[ind] = (int)finais.order_of_key(b+1);
    }

    for(int i: contains){
        cout << (i) << " ";
    }
    cout << endl;

    finais.clear();    
    for(int i=0; i<n; i++) finais.insert(get<1>(v[i]));

    for(int i=n-1; i>0; i--){
        int a, b, ind;
        tie(a, b, ind) = v[i];

        apagar(b);

        belongs[ind]= i-finais.order_of_key(b);
    }

    for(int i: belongs){
        cout << (i) << " ";
    }
    cout << endl;

    return 0;
}
