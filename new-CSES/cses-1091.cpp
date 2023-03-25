// 25/03/23 // 
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
    
    int n, m;
    cin >> n >> m;

    multiset<int> price;

    for(int i=0; i<n; i++){
        int h;
        cin >> h;

        price.insert(h);
    }

    for(int i=0; i<m; i++){
        int maxprice;
        cin >> maxprice;

        set<int>::iterator it = price.upper_bound(maxprice);

        if(it==price.begin()){
            cout << "-1" << endl;
        }
        else{
            it--;

            cout << (*it) << endl;

            price.erase(it);
        }
    }    

    return 0;
}