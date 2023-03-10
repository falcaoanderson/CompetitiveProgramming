#include <iostream>
using namespace std;

int main(){
    int b,n,i,resposta=0;
    int d,c,v;

    while(cin>>b and cin>>n and(b!=0 and n!=0)){

        int saldo[b];

        for(i=0;i<b;i++){
            cin>>saldo[i];
        }

        for(i=0;i<n;i++){
            cin>>d>>c>>v;
            saldo[d-1]-= v;
            saldo[c-1]+= v;
        }
        for (i=0;i<b;i++){
            if(saldo[i]>=0){
                resposta+=1;
            }
        }
        if (resposta==b){
            cout<<"S\n";
        }else{
            cout<<"N\n";
        }

        resposta=0;

    }
    return 0;
}
