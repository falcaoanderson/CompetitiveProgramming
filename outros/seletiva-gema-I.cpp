#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define EB emplace_back
#define endl "\n"
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    
    vector<int> v(2*n);
 
    for(int i=0; i<n; i++){
        cin >> v[i];
        v[i+n] = v[i];
    }
 
    int resp = 0, crr=0;
    for(int i=0; i<2*n-1; i++){
        if(v[i]==1) crr++;
        else crr=0;
 
        resp = max(resp, crr);
    }
 
    cout << resp << endl;
 
    return 0;
}