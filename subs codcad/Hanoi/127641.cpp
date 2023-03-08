#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    int cont=1;

    cout.precision(0);
    cout.setf(ios::fixed);

    while(cin>>n and n!=0){
        cout<<"Teste "<<cont<<endl;
        cout<< pow(2,n) - 1 << endl;
        cont++;
    }

    return 0;
}
