// 02/04/23 //
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define endl "\n"
#define PB push_back
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> v;

    for(int i=0; i<n; i++){
        int curr;
        cin >> curr;

        vector<int>::iterator it = upper_bound(v.begin(), v.end(), curr);

        if(it==v.end()){
            v.PB(curr);
        }
        else{
            (*it) = curr;
        }
    }

    cout << v.size() << endl;
    
    return 0;
}