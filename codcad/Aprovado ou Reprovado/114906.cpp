#include <iostream>
using namespace std;

int main(){
    float a,b;
    cin>>a>>b;

    if ((a + b)*0.5>=7){
        cout<<"Aprovado\n";
    }
    if ((a + b)*0.5>=4 and (a + b)*0.5<7){
        cout<<"Recuperacao\n";
    }
    if ((a + b)*0.5<4){
        cout<<"Reprovado\n";
    }
    return 0;
}
