// 13/01/2019 // 2:32 AM //

#include <iostream>
using namespace std;

long long n;
int eh_primo(){
    if(n==1) return 0;
    if(n==2) return 1;

    if(n%2==0) return 0;
    for(int i=3; i*i<=n; i+=2)
        if(n%i==0)
            return 0;


    return 1;
}

int main(){

    cin >> n;

    if(!eh_primo())
        cout << "N\n";
    else
        cout << "S\n";

    return 0;
}

