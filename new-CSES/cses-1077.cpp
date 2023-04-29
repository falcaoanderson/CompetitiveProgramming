// 29/04/23 // nao funciona, tentar depois
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

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
    
    vector<ll> num(n);
    
    for(int i=0; i<n; i++) cin >> num[i];
    
    for(int i=0; i<k; i++) v.insert(num[i]);
    
    int i_med=(k-1)/2;
    int med = *v.find_by_order(i_med);
    
    ll left=0, right=0;
    
    for(int i=0; i<i_med; i++)   left  += (ll)(*v.find_by_order(i));
    for(int i=i_med+1; i<k; i++) right += (ll)(*v.find_by_order(i));
    
    cout << left << " " << right << endl;
    cout << right - left - ((ll)(k&1 ? 0 : med)) << " ";
    cout << endl << endl;
    
    for(int i=k; i<n; i++){
        int aux = v.order_of_key(num[i-k]);
        if(aux<i_med){
            left -= num[i-k];
        }
        else if(aux>i_med){
            right -= num[i-k];
        }
        else{
            left -= (ll)(*v.find_by_order(i_med-1));
        }
        del(num[i-k]);
        
        med = *v.find_by_order(k/2-1);
        ll nmed = *v.find_by_order(k/2);
        
        cout << left << " " << right << endl;
        
        if(k&1){
            if(num[i]<=med){
                left += num[i];
            }
            else if(med< num[i] && num[i] < nmed){
                left += med;
            }
            else if(num[i]>med){
                right += num[i];
                left += med;
                right -= nmed;
            }
        }        
        v.insert(num[i]);
        cout << left << " " << right << endl;
        med = *v.find_by_order(i_med);
        cout << right - left - ((ll)(k&1 ? 0 : med)) << endl << endl;
    }
    cout << endl;
    
    return 0;
}