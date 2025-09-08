// 06/09/25

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<ll> sum(n), sumsum(n);
    
    ll resp = 0;
    for(int i=0; i<n; i++){
        cin >> sum[i];

        if(i==0){
            sumsum[i] = sum[i];
            resp += sum[i];
        }
        else{
            sum[i] += sum[i-1];
            sumsum[i] = sumsum[i-1] + sum[i];
            
            resp += (ll)(i+1) * sum[i] - sumsum[i-1];
        }
    }

    cout << resp << endl;

    return 0;
}