#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define EB emplace_back
#define endl "\n"
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        int l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;
 
        if(a==b){
            cout << 0 << endl;
        }
        else if(abs(a-b)>=x){
            cout << 1 << endl;
        }
        else if(r-a>=x && r-b>=x){
            cout << 2 << endl;
        }
        else if(a-l>=x && b-l>=x){
            cout << 2 << endl;
        }
        else if(r-a>=x && b-l>=x){
            cout << 3 << endl;
        }
        else if(a-l>=x && r-b>=x){
            cout << 3 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
 
    return 0;
}