#include <iostream>
using namespace std;

int main(){
    string escolha,banda;
    int hora=0;
    float total=0;

    for(int i=0; i<7;i++){
        cin >> escolha;

        if     (escolha=="Revista"){cout<<"entrou em R\n";total+=750;}
        else if(escolha=="Outdoor"){cout<<"entrou em O\n";total+=1500;}
        else if(escolha=="TV"){
            cout<<"entrou em TV\n";
            cin>>hora;
            if(hora>=20){total+=2000;}
            else{total+=1200;}
        }else{
            cout<<"entrou em Rad\n";
            cin >> banda;

            if(banda=="AM"){total+=300;}
            else{total+=500;}
        }
    }
    cout.precision(2);
    cout.setf(ios::fixed);
    cout<<total<<endl;

    return 0;
}
