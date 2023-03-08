#include <iostream>
using namespace std;
#define MAXN 100100

int n, m, intervalos[MAXN], pontos[MAXN];

int buscab(int o){
    int inicio, fim, meio;
    inicio = 1;
    fim = n;

    while(inicio<=fim){
        meio=(inicio+fim)/2;

        if(o>=intervalos[meio] and  o<intervalos[meio+1])return pontos[meio];

        if(o>intervalos[meio])inicio=meio+1;

        if(o<intervalos[meio])fim=meio-1;
    }

    return -1;
}

int main(){
    int o;

    cin >> n >> m;

    intervalos[1]=0;
    intervalos[n+1]=1000000100;

    for(int i=2; i<=n; i++){ // de 2 ate n preencho o vetor com os intervalos
        cin >> intervalos[i];
    }

    for(int i=1; i<=n; i++){
        cin >> pontos[i];
    }

    for(int i=0; i<m; i++){
        cin >> o;
        cout << buscab(o) << " ";
    }
    cout << endl;

    return 0;
}