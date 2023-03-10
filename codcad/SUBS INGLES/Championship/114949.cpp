#include <iostream>
using namespace std;

int main(){
    int cv,ce,cs,fv,fe,fs;
    cin>>cv>>ce>>cs>>fv>>fe>>fs;

    if ((cv*3+ce)>(fv*3+fe)or((cv*3+ce)==(fv*3+fe)and cs>fs)){
        cout<<"C\n";
    }else if ((cv*3+ce)<(fv*3+fe)or((cv*3+ce)==(fv*3+fe)and cs<fs)){
        cout<<"F\n";
    }else{
        cout<<"=\n";
    }
    return 0;
}
