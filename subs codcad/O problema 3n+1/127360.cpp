#include <iostream>
using namespace std;

int cont_global=0;

int pn(int n){
    if(n==1){return 0;}

    cont_global++;

    if(n%2==0){
        return pn(n/2);
    }else{
        return pn(3*n+1);
    }
}


int main(){
    int n;

    cin >> n;
    pn(n);

    cout << cont_global << endl;
    return 0;
}