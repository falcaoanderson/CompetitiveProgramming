#include <iostream>
#include <algorithm>
using namespace std;

struct Pedido{
    int tempo,entrega;
};

bool order(Pedido a, Pedido b){
    return a.entrega < b.entrega;
}

Pedido v[10010];

int main(){
    int n, disp=0, atraso=0, maior=0;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> v[i].tempo >> v[i].entrega;
    }
    sort(v, v+n, order);

    for(int i=0; i<n; i++){
        disp += v[i].tempo;

        if(disp>v[i].entrega){ // ocorre atraso
            atraso = disp - v[i].entrega;
            if(atraso>maior)maior=atraso;
        }

    }

    cout << atraso << endl;

    return 0;
}
