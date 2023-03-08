#include <iostream>
using namespace std;

void subh(int h1,int m1,int h2,int m2){
    if (h2>h1){
        cout<< (h2-h1)*60 +(m2-m1);
    }else{
        cout<< 1440 + (h2-h1)*60 + (m2-m1);
    }
}

int main(){
    int h1, m1, h2, m2;
    while(cin>>h1 and cin>> m1 and cin>> h2 and cin>> m2){
        if(h1==0 and h2 == 0 and m1==0 and m2==0){break;}
        subh(h1,m1,h2,m2);
        cout<<endl;
    }

    return 0;
}
