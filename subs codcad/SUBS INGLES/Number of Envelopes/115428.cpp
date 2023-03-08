#include <iostream>
using namespace std;

int main(){
    short int n,r,ra,i;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>r;
        if(i==0){ra=r;}

        if(r<ra){
            ra=r;
        }
    }
    cout<<ra<<endl;
    return 0;
}
