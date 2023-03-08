// 22/01/19 // 10:59 //

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string letras;

    cin >> letras;

    int tamanho = letras.size(), ult=0;
    bool parada=1;
    int j=1;

    while(parada){
        parada=0;

        if(ult==-1) ult=0;

        for(int i=ult; i<tamanho-1; i++){
            if(letras[i]==letras[i+1]){
                letras.erase(i,2);

                tamanho-=2;
                parada=1;
                ult = i-1;
                j++;

                break;
            }
        }

    }

    if(j%2==0) cout << "yes\n";
    else cout << "no\n";

    return 0;
}
