#include <iostream>
using namespace std;

int main(){
    int t1,t2,t3;
    cin>>t1>>t2>>t3;

    if (t1>t2 and t1>t3){
        if (t2>t3){
            cout<<"3 \n"<<"2 \n"<<"1 \n";
        }
        else{
            cout<<"2 \n"<<"3 \n"<<"1 \n";
        }
    }
    else if (t2>t1 and t2>t3){
        if (t1>t3){
            cout<<"3 \n"<<"1 \n"<<"2 \n";
        }
        else{
            cout<<"1 \n"<<"3 \n"<<"2 \n";
        }
    }

    else{
        if (t1>t2){
            cout<<"2 \n"<<"1 \n"<<"3 \n";
        }
        else{
            cout<<"1 \n"<<"2 \n"<<"3 \n";
        }
    }
    return 0;
}