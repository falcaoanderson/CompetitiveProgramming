// 13/01/2019 // 6:30 PM //
#include <iostream>
#include <cmath>
using namespace std;

int n;

void eh_primo(int x){
    int raiz=sqrt(x);

    for(int i=3; i<=raiz; i+=2)
        if(x%i==0) return;

    cout << x << " ";
}


int main(){
    cin >> n;

    if(n>=2) cout << "2 ";
    for(int i=3; i<=n; i+=2){
        eh_primo(i);
    }
    cout << endl;

    return 0;
}
