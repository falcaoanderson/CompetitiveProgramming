#include <iostream>
using namespace std;

#define ll long long

ll total(ll n){
    return (n*n*(n*n-1) - 8*(n-2)*(n-1))/2;
}

int main(){

    ll n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cout << total(i) << endl;
    }

    return 0;
}