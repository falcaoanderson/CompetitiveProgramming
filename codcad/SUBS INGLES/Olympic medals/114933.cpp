#include <iostream>
using namespace std;

int main(){
    int oa,pa,ba,ob,pb,bb;
    cin>>oa>>pa>>ba>>ob>>pb>>bb;

    if (oa>ob){
        cout<<"A\n";
    }
    else if (ob>oa){
        cout<<"B\n";
    }
    else if (pa>pb){
        cout<<"A\n";
    }
    else if (pb>pa){
        cout<<"B\n";
    }
    else if (ba>bb){
        cout<<"A\n";
    }
    else{
        cout<<"B\n";
    }
    return 0;
}
