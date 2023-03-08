#include <iostream>
using namespace std;

int main(){
    int a1,l1,a2,l2;

    cin>>a1>>l1>>a2>>l2;

    if (a1*l1>a2*l2){
        cout<<"Primeiro\n";
    }
    if (a1*l1<a2*l2){
        cout<<"Segundo\n";

    }
    if(a1*l1==a2*l2){
        cout<<"Empate\n";
    }
    return 0;
}