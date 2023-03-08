#include <iostream>
using namespace std;

int main(){
    int n,totals=0,s1=0,s2=0,i;
    cin>>n;
    int v[n];

    for (i=0;i<n;i++){
        cin>>v[i];
        totals+=v[i];
    }
    s2=totals;
    for (i=0;i<n;i++){
        s1+=v[i];
        s2-=v[i];
        if (s1==s2){
            cout<<i+1<<endl;
            break;
        }
    }
}