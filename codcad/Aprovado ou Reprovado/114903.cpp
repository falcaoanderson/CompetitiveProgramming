#include <iostream>
using namespace std;

int main(){
    double a,b;

    cin>>a>>b;
    //nota = (a + b)*0.5;

    if ((a + b)*0.5>=7){
        cout<<"Aprovado\n";
    }
    else if ((a + b)*0.5>=4){
        cout<<"Recuperacao\n";
    }
    else{
        cout<<"Reprovado\n";
    }
    return 0;
}
