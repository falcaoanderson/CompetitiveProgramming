#include <iostream>
using namespace std;

int main(){
    int m,n,i;
    int l,t,k=0;
    int lm[1000],ln[1000],s[1000];
    cin>>m>>n;

    for(i=0;i<m;i++){
        cin>>lm[i];
    }
    for(i=0;i<n;i++){
        cin>>ln[i];
    }
    if (m>=n){
        l=m;
    }
    else{
        l=n;
    }

    for(i=l-1;i>=0;i--){
        if (i>=m){
            lm[i]=0;
        }
        if (i>=n){
            ln[i]=0;
        }
    }
    for(i=l-1;i>=0;i--){
        t=lm[i]+ln[i];

        if(t==0){s[i]=0;}
        else if(t==1){s[i]=1;}
        else if(t==2){
            s[i]=0;
            if(i==0){
                k=1;
            }else{
                lm[i-1]+=1;
            }
        }else if(t==3){
            s[i]=1;
            if(i==0){
                k=1;
            }else{
                lm[i-1]+=1;
            }
        }
    }
    t=l;
    for(i=l-1;i>=0;i--){
        if(s[i]==0){
            t-=1;
        }else{
            break;
        }
    }
    if(k==1){
        cout<<"1 ";
    }
    for(i=0;i<t;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
