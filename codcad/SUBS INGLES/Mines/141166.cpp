// 02/03/19 // 5:30 PM //

#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 40100

int n;
bool crivo[MAXN];

void primos(int x){
    int limite = sqrt(x);

    crivo[1]=1;

    for(int i=2; i<=limite; i++){
        if(!crivo[i]){
            for(int j = i*i; j<=x; j+=i)
                crivo[j]=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    n = n/100;

    primos(n);

    long long temp, total=0LL;

    for(int i=1; i<=n; i++){
        cin >> temp;

        if(!crivo[i])
            total += temp;
    }

    cout << total << "\n";

    return 0;
}
