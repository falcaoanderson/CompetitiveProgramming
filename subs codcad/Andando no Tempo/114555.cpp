#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;

    if (a==b or a==c or b==c){
        cout<<"S\n";
    }
    else{
        if (a+b+c==2*a or a+b+c==2*b or a+b+c==2*c ){
            cout<<"S\n";
            }
        else{
            cout<<"N\n";
        }
    }
    return 0;
}
