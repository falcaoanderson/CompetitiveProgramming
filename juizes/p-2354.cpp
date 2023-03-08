#include <iostream>
using namespace std;

bool primo(int n){
    if(n==1){return false;}
    if(n==2){return true;}

    for(int i=2; i<n; i++)if(n%i==0)return false;

    return true;
}

int main(){
    int a,b;
    cin >> a >> b;

    if(primo(a)==false){
        cout << "O numero " << a << " nao eh primo.\n";
    }
    else if(primo(b)==false){
        cout << "O numero " << b << " nao eh primo.\n";
    }
    else{
        if(primo(a+b))cout << "A soma de " << a << " e " << b <<  " eh um primo.\n";
        else cout << "A soma de " << a << " e " << b <<  " nao eh um primo.\n";

    }
    return 0;
}
