#include <iostream>
using namespace std;

int main(){
    int n,b,i;
    int x,cont=0;

    while(cin>>n and cin>>b and(n!=0 and b!=0)){

        int nlista[n];
        int blista[b];
        int npl[(b*(b-1)/2)];


        for(i=1;i<=n;i++){
            nlista[i-1]=i;
        }
        for(i=0;i<b;i++){
            cin>>blista[i];
        }


        for(i=0;i<b;i++){
            for(x=i+1;x<b;x++){
                npl[cont]=blista[i]-blista[x];

                if(npl[cont]<0){npl[cont]=npl[cont]*-1;}
                cont++;
            }
        }
        cont=0;
        for(i=0;i<n;i++){
            for(x=0;x<(b*(b-1)/2);x++){
                if(nlista[i]==npl[x]){
                    cont++;
                    break;
                }
            }
            if(cont==0){
                cont=2;
                cout<<"N\n";
                break;
            }
            cont=0;
        }
        if(cont==0){
            cout<<"Y\n";
        }
        cont=0;
    }
}