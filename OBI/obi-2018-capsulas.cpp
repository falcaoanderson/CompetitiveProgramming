// 22/04/2019 // 4:20 PM //

#include <iostream>

using namespace std;

#define MAXN 100010
#define MAXD 100000100

int n, f;
int v[MAXN];

int valor(int dias){
    int soma=0;

    for(int i=1; i<=n; i++)
        soma += dias/v[i];

    return soma;
}

int buscab(){
    int inicio = 1, fim = MAXD;
    int meio, chute, melhor;

    while(inicio<=fim){
        meio = (inicio+fim)/2;

        chute = valor(meio);

        if(chute>=f){
            melhor = meio;
            fim = meio-1;
        }
        if(chute<f)
            inicio = meio + 1;
    }

    return melhor;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> f;

    for(int i=1; i<=n; i++)
        cin >> v[i];

    cout << buscab() << "\n";

    return 0;
}
