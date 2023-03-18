#include <iostream>

using namespace std;

#define ll long long

const ll MOD = 1e9+7;

ll exp(ll a, int b){
    a %= MOD;

    if(b==0){
        return 1LL;
    }
    if(b==1){
        return a;
    }
    if(b&1){
        return (a * exp(a, b-1))%MOD;
    }
    return exp((a*a)%MOD, b/2);
}

int main(){

    int n;
    cin >> n;

    cout << exp(2LL, n) << endl;

    return 0;
}