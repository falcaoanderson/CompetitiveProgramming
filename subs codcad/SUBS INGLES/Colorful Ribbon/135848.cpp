#include <iostream>
#include <cmath>
using namespace std;

#define MAXN 10010

int n, p=0, v[MAXN], zeros[MAXN];

int buscab(int i){
    int inicio, fim, meio, d, menor=MAXN;
    inicio=1;
    fim=p;

    while(inicio<=fim){
        meio=(inicio+fim)/2;

        d = zeros[meio]-i;

        if(d==1 or d==-1) return 1; // se d=1 entao achei a melhor solucao possivel logo retorno

        if(d>0) fim = meio-1;


        if(d<0) inicio = meio+1;

        d=abs(d);
        //cout << "Comparacao (" << i <<") - " << d << " <=> " << menor << endl;
        if(d<menor) menor=d;
    }

    return menor;
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        if(v[i]==0)
            zeros[++p]=i;
    }

    for(int i=1; i<=n; i++){
        if(v[i]==0){
            cout << "0 ";
            continue;
        }

        int cor = buscab(i);
        if(cor>=9)
            cout << "9 ";
        else
            cout << cor << " ";
    }
    cout << endl;

    return 0;
}
