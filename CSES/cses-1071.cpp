#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;

        if(y<=x){
            if(x&1){
               cout << (x-1)*(x-1) + y << endl;
            }
            else{
                cout << x*x + 1 - y << endl;
            }
        }
        else{
            if(y&1){
                cout << y*y + 1 - x << endl;
            }
            else{
                cout << (y-1)*(y-1) + x << endl;
            }
        }
    }

    return 0;
}
