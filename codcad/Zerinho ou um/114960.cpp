#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;

    if      (b==c and a!=b){cout<<"A\n";}
    else if (a==c and b!=a){cout<<"B\n";}
    else if (a==b and c!=a){cout<<"C\n";}
    else{cout<<"*\n";}

    return 0;
}
