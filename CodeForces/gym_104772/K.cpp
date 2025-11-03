/*
18/10/25

*/
#include <bits/stdc++.h>

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"
#define ll long long

using namespace std;

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        ll x;
        cin >> x;

        int resp = 0;

        while(x>0){
            ll i=1;
            while((1LL<<(i+1LL))-1LL <= x) i++;
            x -= (1LL<<i)-1LL;

            if(x>0) resp++;
        }

        cout << resp << endl;
    }
    
    return 0;
}