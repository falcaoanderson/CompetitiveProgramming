#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define ll long long

ll min(ll a, ll b){
    return (a<b? a: b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> v(n, 0LL);
    ll sum=0LL;
    
    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }

    ll sol = sum;

    for(int mask=0; mask<(1<<n); mask++){
        ll total = 0LL;
        
        for(int i=0; i<n; i++){
            if((mask&(1<<i)) != 0)
                total += v[i];
        }

        sol = min(sol, abs(sum-2*total));
    }

    cout << sol << endl;

    return 0;
}