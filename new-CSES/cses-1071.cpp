#include <iostream>

using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;

        ll n = max(x, y);
        
        ll val = 1LL+n*(n-1) + (ll)(n&1? y-x: x-y);

        cout << val << "\n";
    }

    return 0;
}