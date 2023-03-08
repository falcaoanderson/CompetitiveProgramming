#include <iostream>
using namespace std;

int main(){
    unsigned short int h1,m1,h2,m2;

    while(1>0){
            cin>>h1>>m1>>h2>>m2;
            if(h1==0 and m1==0 and h2==0 and m2==0){break;}
            if (h1>h2 or (h1==h2 and m1>m2)){
                m2=m2+1440;
            }
            cout<<60*(h2-h1)+m2-m1<<endl;
    }
    return 0;
}
