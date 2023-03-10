#include <iostream>
using namespace std;

int tmoeda[6] = {100,50,25,10,5,1};

int main(){
    int dinheiro,moedas=0,i;
    cin >> dinheiro;

    for(i=0; i<6; i++){
        moedas += dinheiro/tmoeda[i];
        dinheiro -= (dinheiro/tmoeda[i])*tmoeda[i];
        if(dinheiro==0)break;
    }

    cout << moedas << endl;
    return 0;
}
