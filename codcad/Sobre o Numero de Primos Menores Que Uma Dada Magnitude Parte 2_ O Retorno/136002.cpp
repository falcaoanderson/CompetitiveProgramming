// 14/01/19// 10:22 PM //

#include <iostream>

using namespace std;

#define MAXN 10000010

int primos[MAXN]; // 0 para primo // 1 para composto //

void crivo(int n){
    primos[1] = 1; // defino 1 como composto

    for(int i=2; i<=n; i++){           // para cada elemento do meu vetor
        if(primos[i]==0){              // se ele for primo
            for(int j=2; i*j<=n; j++){ // para cada multiplo dele
                primos[j*i]=1;         // marco o multiplo como composto
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    crivo(n);

    if(n>1) cout << "2 ";
    for(int i=3; i<=n; i+=2)
        if(primos[i]==0) cout << i << " ";

    cout << "\n";

    return 0;
}
