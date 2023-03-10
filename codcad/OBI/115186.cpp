#include <iostream>
using namespace std;

int main(){
    int num,corte,n1,n2;
    unsigned short int i=0,z=0;
    cin>>num>>corte;

    while (i<num){
        cin>>n1>>n2;
        if(n1+n2>=corte){
            z=z+1;
        }
        i = i +1;
    }
    cout<<z<<endl;
    return 0;
}