#include <iostream>
using namespace std;

int main(){
    char tipo;
    int quant,tcaps = 0;

    for(int i=0; i<7; i++){
        cin >> quant;
        cin >> tipo;

        if(tipo=='p' or tipo =='P'){
            tcaps += quant*10;
        }
        else{
            tcaps += quant*16;
        }
    }

    cout << tcaps << endl << tcaps*2/7 << endl;

    return 0;
}
