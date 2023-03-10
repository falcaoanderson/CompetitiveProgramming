#include <iostream>
#include <cmath>
using namespace std;

int Hanoi(int n){
    if (n==1){
        return 1;
    }
    return (1 + 2*(Hanoi(n-1)));
}

int main(){
    int n;
    int cont=1;

    while(cin>>n and n!=0){
        cout<<"Teste "<<cont<<endl;
        cout<< Hanoi(n)   << endl;
        cont++;
    }

    return 0;
}