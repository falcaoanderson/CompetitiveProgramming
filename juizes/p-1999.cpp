#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    float c=0;
    string gabarito,resposta;
    bool parada=true;

    cin >> n;
    getchar();

    int tamanho = 2*n-1;

    while(true){
        getline(cin,gabarito);
        if(gabarito.size()==tamanho){
            break;
        }
        cout << "Gabarito de tamanho errado. Entre com o novo gabarito:\n";
    }

    while(true){
        while(true){
            getline(cin,resposta);
            if(resposta=="sair"){parada=false; break;}
            if(resposta.size()==tamanho){break;}
            cout << "Tamanho da resposta diferente do tamanho do gabarito.\n";
        }
        if(parada==false){break;}
        c = 0;
        for(int i=0; i<tamanho; i++){
            if(resposta[i]==gabarito[i]){
                c++;
            }
        }
        c = c - n + 1;
        c = (c*100)/n;

        printf("Percentual de acertos: %.1f\n",c);
    }

    return 0;
}
