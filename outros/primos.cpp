#include <iostream>

using namespace std;

#define ll long long
const ll MOD = 1e9+7;

ll exp1(ll num, ll pot){

    if(!pot) return 1ll;

    return (num%MOD * exp1(num, pot-1ll)%MOD)%MOD;
}

ll exp2(ll num, ll pot){

    if(!pot) return 1ll;

    ll temp = exp2(num, pot/2ll)%MOD;

    if(pot&1) return (num%MOD * (temp * temp)%MOD)%MOD;

    return (temp*temp)%MOD;
}

int main(){

    cout << exp2(2ll,10000000);

    return 0;
}
