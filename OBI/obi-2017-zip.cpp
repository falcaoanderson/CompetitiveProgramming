#include <iostream>
using namespace std;

int main(){
    int l1,l2,c1,c2;
    cin>> l1>>l2>>c1>>c2;

    if (l1==l2){
        l1=2*(l1+l2);
    }else if(l1==l2+1 or l1+1==l2){
        l1=3*(l1+l2);
    }else{
        l1=l1+l2;
    }
    if (c1==c2){
        c1=2*(c1+c2);
    }else if(c1==c2+1 or c1+1==c2){
        c1=3*(c1+c2);
    }else{
        c1=c1+c2;
    }

    if(l1>c1){cout<<"Lia\n";}
    else if (l1<c1){cout<<"Carolina\n";}
    else{cout<<"empate\n";}
    return 0;
}
