#include <iostream>
using namespace std;
#define MAXN 100100

int n, k, v[MAXN], a, b;

int buscab(){
    int inicio, fim, meio, soma;

    for(int i=1; i<=n; i++){
        inicio = i;
        fim = n;
        while(inicio<=fim){
            meio = (inicio+fim)/2;
            soma = v[i]+v[meio];

            if(soma==k){
                a=v[i];
                b=v[meio];
                return 0;
            }
            if(soma>k)fim=meio-1;
            if(soma<k)inicio=meio+1;
        }
    }
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> v[i];

    cin >> k;

    buscab();

    cout << a << " " << b << endl;

    return 0;
}