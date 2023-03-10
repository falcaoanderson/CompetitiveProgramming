#include <iostream>
using namespace std;

int main(){
    short int n,maior;

    cin>>n;
    maior=n;

    while (1>0){
        cin>>n;
        if (n==0){
            break;
        }
        if (n>maior){
            maior=n;
        }
    }
    cout<<maior<<endl;
    return 0;
}



