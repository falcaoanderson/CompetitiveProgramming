#include <iostream>
using namespace std;

int main(){
    int t1,t2,t3;
    cin>>t1>>t2>>t3;
    if (t1>t2 and t1>t3 and t2>t3){
        cout<<"3 \n"<<"2 \n"<<"1 \n";
    }
    if (t1>t2 and t1>t3 and t3>t2){
        cout<<"2 \n"<<"3 \n"<<"1 \n";
    }
    if (t2>t1 and t2>t3 and t1>t3){
        cout<<"3 \n"<<"1 \n"<<"2 \n";
    }
    if (t2>t1 and t2>t3 and t3>t1){
        cout<<"1 \n"<<"3 \n"<<"2 \n";
    }
    if (t3>t1 and t3>t2 and t1>t2){
        cout<<"2 \n"<<"1 \n"<<"3 \n";
    }
    if (t3>t1 and t3>t2 and t2>t1){
        cout<<"1 \n"<<"2 \n"<<"3 \n";
    }
    return 0;
}