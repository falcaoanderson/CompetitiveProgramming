#include <iostream>
using namespace std;

int main(){
    short int l, r, d;
    cin>> l >> r >> d;

    if(r>50 and l<r and r>d){
        cout<<"S"<<endl;
    }else{
        cout<<"N"<<endl;
    }
    return 0;
}
