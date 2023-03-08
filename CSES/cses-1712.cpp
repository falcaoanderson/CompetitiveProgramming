// 14/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

const ll MOD = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){
    if(b==0LL) return 1LL;

    if(b&1LL) return (a*exp(a, b-1LL, m))%m;
    else    return exp((a*a)%m, b/2, m)%m;
}

int main(){
    fast_io;

    int n;
    cin >> n;

    while(n--){
        ll a, b, c;
        cin >> a >> b >> c;

        cout << exp(a, exp(b, c, MOD-1)) << endl;
    }
    
    return 0;
}
