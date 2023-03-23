// 23/03/23 // 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define ll long long
#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; ll size;
    cin >> n >> size;
    
    multiset<ll> weight;
    for(int i=0; i<n; i++){
        ll temp; 
        cin >> temp;
        weight.insert(temp);
    }

    for(int i=0; i<n; i++){
        multiset<ll>::iterator first = weight.begin();
        
        multiset<ll>::iterator second = weight.upper_bound(size-(*first));
        
        cout << (*first) << " -> ";

        if(second==weight.begin()){
            cout << "-1"; 
        }
        else{
            cout << (*second);
        }
        weight.erase(first);
        cout << endl;
    }
    cout << endl;

   

    return 0;
}