#include <iostream>
using namespace std;

int main(){
    string email;
    int ponto=0, arroba=0;
    bool usuario=false, dominio=false, tipod=false, pais=false;
    int tamanho;

    while(true){
        cin >> email;

        if(email=="sair"){break;}
        tamanho = email.size()-1;

        for(int i=0; i<email.size(); i++){
            if(email[i]=='.' and i!=tamanho){
                ponto+=1;

                if(ponto==1){
                    if(email[i+1]!='.'){
                        tipod=true;
                    }
                }
                if(ponto==2){
                    if(email[i+1]!='.'){
                        pais = true;
                    }
                }
            }
            if(email[i]=='@' and i!=tamanho){
                arroba+=1;
                if(email[i+1]!='.'){
                    dominio=true;
                }
            }
            if(email[0]!='@'){
                usuario=true;
            }
        }

        if(usuario and dominio and tipod and pais and arroba==1 and ponto == 2){
            cout << "certo" <<endl;
        }
        else{
            cout << "errado" <<endl;
        }
        ponto=0;
        arroba=0;
        usuario=false;
        dominio=false;
        tipod=false;
        pais=false;
    }

    return 0;
}
