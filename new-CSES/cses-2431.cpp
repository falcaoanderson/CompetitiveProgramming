// 21/03/23 // 
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

int digit(int k){
    ll pot = 10;
    int n=1;

    while(pot-1<k){
        pot *= 10;
        n++;
    }

    cout << pot << " " << n << endl;
    
    ll passo = exp(10, n-1);  
    ll val = passo;

    while(val < passo){
        if(val+passo>k) passo /= 10;

        val += passo;
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while(q--){
        int temp;
        cin >> temp;

        digit(temp);
    }

    return 0;
}