// 13/01/2019 // 6:19 PM //

#include <iostream>
#include <cmath>
using namespace std;

long long n;

bool eh_possivel(){
    if(n<=2) return false;

    if(n%2==0) return true;

    float raiz=sqrt(n);

    for(int i=3; i<=raiz; i+=2)
        if(n%i==0) return true;

    return false;
}

int main(){
    cin >> n;

    if(eh_possivel())
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
