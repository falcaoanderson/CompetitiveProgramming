#include <iostream>
using namespace std;

int main(){
    int n,t,ta=0,total=0,i;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>t;
        if (t>=ta+10 or i==0){
            total+=10;
        }else{
            total+= t-ta;
        }
        ta=t;
    }
    cout<<total<<endl;
    return 0;
}
