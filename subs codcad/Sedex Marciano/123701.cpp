#include <iostream>
using namespace std;
#include <cmath>

int main(){
    int l,a,p,r;

    cin>>l>>a>>p>>r;

    l=sqrt(l*l+a*a+p*p);

    if(l<=r*2){
        cout<<"S"<<endl;
    }else{
        cout<<"N"<<endl;
    }
    return 0;
}
