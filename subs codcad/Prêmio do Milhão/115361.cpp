#include <iostream>
using namespace std;

int main(){
    int s=0,d,v,i=1,r=0;
    cin>>d;

    while (i<=d){
        cin>>v;
        s=s+v;
        if (s>=1000000 and r==0){
            r=i;
        }
        i=i+1;
    }
    cout<<r;
    return 0;
}

