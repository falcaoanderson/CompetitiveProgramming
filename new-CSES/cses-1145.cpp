// 25/04/23 //
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
    
    vector<int> v(n, 0);
    
    for(int i=0; i<n; i++) cin >> v[i];
    
    vector<int> s;
    s.PB(v[0]);
    
    for(int i=1; i<n; i++){
        vector<int>::iterator it = lower_bound(s.begin(), s.end(), v[i]);
 
        if(it==s.end()){
            s.PB(v[i]);
        }
        else{
            (*it) = v[i];
        }
    }
    
    cout << s.size() << endl;
 
    return 0;
}
