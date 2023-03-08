#include <iostream>
#include <cmath>
using namespace std;

bool primo(int n){
    if(n==1){return false;}
    if(n==2){return true;}

    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n,cont=0, i=2;
    cin >> n;

    while(cont<n){
        if(primo(i)){
            cout << i << endl;
            cont++;
        }
        i++;
    }
    return 0;
}
