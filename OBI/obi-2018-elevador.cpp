// 28/04/19 // 6:29 PM //

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1010
#define MAXNMAXN 1000100

int n;
int v[MAXNMAXN], linhas[MAXN], colunas[MAXN], d1=0, soma=0, cont=0, celula;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> celula;

            linhas[i]  += celula;
            colunas[j] += celula;
            if(i==j) d1+= celula;

            v[++cont]   = celula;
            soma       += celula;
        }
    }

    soma /= n;

    sort( v+1, v+(n*n+1) ) ;

    if(d1!=soma){                                 // testa diagonal principal
        cout << "0\n";
        return 0;
    }

    for(int i=1; i<=n; i++)
        if(linhas[i]!=soma || colunas[i]!=soma){  // testa linhas e colunas
            cout << "0\n";
            return 0;
        }

    for(int i=1; i<=n*n; i++)                     // testa se o quadrado contem todos os numeros de 1 a n²
        if(v[i] != v[i-1]+1){
            cout << "0\n";
            return 0;
        }


    cout << soma << "\n";

    return 0;
}
