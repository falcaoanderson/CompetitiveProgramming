#include <iostream>
using namespace std;

int main(){
    int n,v,vt,ca=0,cf=0,i;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>v;
        if(i==0){vt=v;}

        if (v==vt){
            ca++;
            if (ca>cf){
                cf=ca;
            }
        }else{
            ca=1;
        }
        vt=v;
    }

    cout<<cf<<endl;
    return 0;
}
