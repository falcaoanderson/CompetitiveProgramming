#include <iostream>
using namespace std;

int main(){
    short int pt,f,np,i;
    cin>>pt>>f;

    for(i=1; i<=f; i++){
        cin>>np;
        pt += np;

        if (pt<0){pt=0;}
        if (pt>100){pt=100;}
        }
    cout<<pt;
    return 0;
}
