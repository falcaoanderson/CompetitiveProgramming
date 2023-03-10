#include <iostream>
using namespace std;

int main(){
    short int h,p,f,d;
    cin>>h>>p>>f>>d;

    while (1>0){
        f = f + d;
        if (f==16){f=0;}
        if (f==-1){f=15;}
        if (f==h){
            cout<<"S\n";
            break;
        }
        if(f==p){
            cout<<"N\n";
            break;
        }
    }
}
