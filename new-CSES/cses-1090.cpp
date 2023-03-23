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
    
    int total = 0;
    while(!weight.empty()){
        multiset<ll>::iterator first = weight.begin();
        weight.erase(first);

        multiset<ll>::iterator second = weight.upper_bound(size-(*first));

        total++;
        //if(weight.empty()) break;
        if(second!=weight.begin()){
            second--;
            weight.erase(second);
        }
    }

    cout << total << endl;

    return 0;
}