// 09/02/19 // 5:19 //

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 50010

int n;
int v[MAXN];

int soma_maxima(){
    int saida=0, maior=0;

    for(int i=0; i<n; i++){ // para cada elemento do meu vetor

        maior = max(0, maior + v[i]);

        saida = max(saida, maior);
    }

    return saida;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++) cin >> v[i];

    cout << soma_maxima() << "\n";

    return 0;
}
