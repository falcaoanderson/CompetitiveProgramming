// 22/01/19 // 8:02 PM //

#include <iostream>
#include <cmath>
using namespace std;

#define MAXN 2000000

bool primos[MAXN];

void crivo(int x){
    int raiz = sqrt(x);

    for(int i=2; i<=raiz; i++){
        if(!primos[i]){
            for(int j=i*i; j<=x; j+=i){
                primos[j] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x = 100;
    crivo(x);

    for(int i=2; i<=x; i++){
        if(!primos[i]) cout << i << "\n";
    }

    return 0;
}

