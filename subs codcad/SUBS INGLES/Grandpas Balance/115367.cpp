#include <iostream>
using namespace std;

int main(){
    int d,s,ms ,t,i=1;
    cin>>d>>s;

    ms = s;

    while(i<=d){
        cin>>t;
        s = s + t;
        if (s<ms){
            ms=s;
        }
        i=i+1;
    }
    cout<<ms;
    return 0;
}
