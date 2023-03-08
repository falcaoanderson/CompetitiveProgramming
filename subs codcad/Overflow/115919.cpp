#include <iostream>
using namespace std;

int main(){
    int n,p,q;
    char c;
    cin>>n>>p>>c>>q;

    if (c=='+'){
        if(p+q<=n){
            cout<<"OK\n";
        }else{
            cout<<"OVERFLOW\n";
        }
    }else{
        if(p*q<=n){
            cout<<"OK\n";
        }else{
            cout<<"OVERFLOW\n";
        }
    }
    return 0;
}
