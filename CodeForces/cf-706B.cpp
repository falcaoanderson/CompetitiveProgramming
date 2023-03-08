// 26/05/19 // 10:05 PM //

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100010

int n, dias, valor;
int preco[MAXN];

int buscab(int x){
    int inicio, meio, fim, resp=-1;

    inicio = 0;
    fim = n;

    while(inicio<=fim){
        meio = (inicio+fim)/2;

        //cout << meio << "\n";

        if(preco[meio]<=x){
            resp = meio;
            inicio = meio+1;
        }
        else if(preco[meio]>x)
            fim = meio-1;
    }

    return resp;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++) cin >> preco[i];

    cin >> dias;

    sort(preco+1, preco+n+1);

    for(int i=0; i<dias; i++){
        cin >> valor;

        cout << buscab(valor) << "\n";
    }

    return 0;
}
