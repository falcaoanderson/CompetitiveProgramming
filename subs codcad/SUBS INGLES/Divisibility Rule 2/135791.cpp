#include <iostream>
using namespace std;

int main(){
    string num;
    int aux=1;

    cin >> num;

    int u = num.size()-1, soma=0;

    for(int i=0; i<=u; i++){
        soma += (num[i]-'0');
    }

    if(num.size()<=1){
        if((num[u]-'0')%4==0)
            cout << "S\n";
        else
            cout << "N\n";
    }
    else{
        aux = 10*(num[u-1]-'0') + (num[u]-'0');
        if(aux%4==0)
            cout << "S\n";
        else
            cout << "N\n";
    }

    if(soma%9==0)
        cout << "S\n";
    else
        cout << "N\n";

    if(num.size()==1 && num!="0")
        cout << "N\n";
    else if(aux%25==0 or num=="0")
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}