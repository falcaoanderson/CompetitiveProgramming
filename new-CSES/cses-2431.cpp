// 22/03/23 // 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define endl "\n"

ll exp(ll a, int b){
    if(b==0){
        return 1LL;
    }
    if(b==1){
        return a;
    }
    if(b&1){
        return (a * exp(a, b-1));
    }
    return exp((a*a), b/2);
}
ll f(ll n){
    //return ((n+1)*9LL*exp(10LL, n)-exp(10LL,n+1)+1LL)/9LL;
    
    ll resp = 0LL, x = 9LL;

    for(int i=1; i<=n; i++){
        resp += x*i;
        x *= 10LL;
    }
    
    return resp;
}

ll digit(ll k){
    int n=1;

    while(f(n)<k){
        n++;
    }

    ll faltam = k - f(n-1);
    ll number = exp(10, n-1) + (faltam-1)/n;
    ll pos = n-(faltam-1)%n-1;
    
    return  (number/exp(10, pos))%10;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;

    while(q--){
        ll temp;
        cin >> temp;

        cout << digit(temp) << endl;
    }
    
    return 0;
}