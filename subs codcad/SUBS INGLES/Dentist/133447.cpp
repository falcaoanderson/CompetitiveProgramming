#include <iostream>
#include <algorithm>
using namespace std;

struct Consulta{
    int h1,h2;
};

bool order(Consulta a, Consulta b){
    return a.h2 < b.h2;
}

Consulta v[10005];

int main(){
    int n,cont=0;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> v[i].h1 >> v[i].h2;
    }

    sort(v, v+n, order);

    int temp=-1;

    for(int i=0; i<n; i++){
        if(v[i].h1>=temp){
            cont++;
            temp=v[i].h2;
        }
    }

    cout << cont;

    return 0;
}
