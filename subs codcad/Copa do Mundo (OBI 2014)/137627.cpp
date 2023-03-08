// 02/02/19 // 9:17 PM //


#include <iostream>
#include <algorithm>

using namespace std;

#define MAXV 110
#define MAXA 1000

struct Aresta{
    int d;
    int x, y;
};

int nver, nare, nferro, nrodo;
int pai[MAXV], peso[MAXV];
Aresta grafo[MAXA];

int buscap(int i){
    if(pai[i]==i) return i;

    return pai[i] = buscap(pai[i]);
}

int juntar(int i, int j){
    i = buscap(i);
    j = buscap(j);

    if(peso[i] < peso[j])
        pai[i] = j;
    else if(peso[i] > peso[j])
        pai[j] = i;
    else{
        pai[i] = j;
        peso[j]++;
    }
}

bool order(Aresta a, Aresta b){
    return a.d < b.d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nver >> nferro >> nrodo;
    nare = nferro + nrodo;

    for(int i=1; i<=nferro; i++)
        cin >> grafo[i].x >> grafo[i].y >> grafo[i].d;
    for(int i=nferro+1; i<=nrodo+nferro; i++)
        cin >> grafo[i].x >> grafo[i].y >> grafo[i].d;

    for(int i=1; i<=nver; i++)
        pai[i] = i;

    sort(grafo+1, grafo+nferro+1, order);
    sort(grafo+nferro+1, grafo+nferro+nrodo+1, order);

    int total=0;
    for(int i=1; i<=nare; i++){
        if( buscap(grafo[i].x) != buscap(grafo[i].y) ){
            juntar(grafo[i].x, grafo[i].y);

            total += grafo[i].d;
        }
    }

    cout << total << "\n";

    return 0;
}

