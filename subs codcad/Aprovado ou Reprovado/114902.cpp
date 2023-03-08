#include <iostream>
using namespace std;

int main(){
    double a,b,nota;

    cin>>a>>b;
    nota = (a + b)*0.5;

    if (nota>=7){
        cout<<"Aprovado\n";
    }
    else if (nota>=4){
        cout<<"Recuperacao\n";
    }
    else{
        cout<<"Reprovado\n";
    }
    return 0;
}
