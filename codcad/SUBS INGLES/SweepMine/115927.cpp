#include <iostream>
using namespace std;

int main(){
    int n,i,m;
    cin>>n;
    int v[n];

    for(i=0;i<n;i++){
        cin>>v[i];
    }

    for(i=0;i<n;i++){
        if(n==1){
            cout<<v[0];
            break;
        }
        if(i==0){
            cout<<v[0]+v[1]<<endl;
        }else if(i==n-1){
            cout<<v[i]+v[i-1]<<endl;
        }else{
            cout<< v[i-1] + v[i] + v[i+1]<<endl;
        }
    }

    return 0;
}