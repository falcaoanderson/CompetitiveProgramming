#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define EB emplace_back
#define endl "\n"
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, k, l, r;
    cin >> n >> k >> l >> r;
 
    if(n*l <= k && k <= n*r){
        cout << "S" << endl;
    }
    else{
        cout << "N" << endl;
    }
 
    return 0;
}