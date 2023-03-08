#include <iostream>
using namespace std;

int main(){
    short int t1, t2, t3;
    cin>> t1 >> t2 >> t3;

    if(t1<t2 and t1<t3 and t2<t3){
        cout<<"1"<<endl<<"2"<<endl<<"3"<<endl;
    }
    else if(t1<t2 and t1<t3 and t3<t2){
        cout<<"1"<<endl<<"3"<<endl<<"2"<<endl;
    }
    else if(t2<t1 and t2<t3 and t1<t3){
        cout<<"2"<<endl<<"1"<<endl<<"3"<<endl;
    }
    else if(t2<t1 and t2<t3 and t3<t1){
        cout<<"2"<<endl<<"3"<<endl<<"1"<<endl;
    }
    else if(t3<t1 and t3<t2 and t1<t2){
        cout<<"3"<<endl<<"1"<<endl<<"2"<<endl;
    }
    else if(t3<t1 and t3<t2 and t2<t1){
        cout<<"3"<<endl<<"2"<<endl<<"1"<<endl;
    }
    return 0;
}
