#include <iostream>
using namespace std;

int main(){
    int cv,ce,cs,fv,fe,fs;
    cin>>cv>>ce>>cs>>fv>>fe>>fs;

    if ((cv*3+ce)>(fv*3+fe)){
        cout<<"C\n";
    }else if ((cv*3+ce)<(fv*3+fe)){
        cout<<"F\n";
    }else if (cs>fs){
        cout<<"C\n";
    }else if (cs<fs){
        cout<<"F\n";
    }else{
        cout<<"=\n";
    }
    return 0;
}
