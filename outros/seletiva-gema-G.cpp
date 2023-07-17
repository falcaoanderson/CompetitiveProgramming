#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define EB emplace_back
#define endl "\n"
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
 
    set<int> v;
 
    for(int i=0; i<4; i++){
        int val;
        cin >> val;
 
        v.insert(val);
    }
 
    cout << 4-(int)v.size() << endl;
 
 
    return 0;
}