#include <iostream>
using namespace std;

int main(){

    int pontos, total=0;

    for(int i=0; i<6; i++){
        cin>>pontos;
        total += pontos;
    }

    if(total>=100){cout<<"Classificado"<<endl;}
    else{cout<<"Eliminado"<<endl;}

    return 0;
}
