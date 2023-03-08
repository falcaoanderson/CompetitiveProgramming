#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int i, n, d, c, tipo=0;

    double bac, maior=0;

    cin>>n;

    for(i=0; i<n; i++){
        cin>>d>>c;

        bac = c*log10(d); // comparar os numeros usando logaritimo de base 10
                          // log(d^c)=c*log(d)
        if(bac>maior){
            maior=bac;
            tipo=i;
        }
    }

    cout<< tipo <<endl;
    return 0;
}
