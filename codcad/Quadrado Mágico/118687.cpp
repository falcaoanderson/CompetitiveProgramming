#include <iostream>
using namespace std;

int main(){
    int n,i,j;
    int s=0,l=0,c=0,d1=0,d2=0;

    cin>>n;
    int q[n][n];

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>> q[i][j];
            s += q[i][j];
        }
    }
    s=s/n;

    while(true){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                l += q[i][j];
            }
            if(l!=s){
                cout<<"-1\n";
                l=-1;
                break;
            }
            l=0;
        }
        if(l==-1){
            break;
        }

        for(j=0; j<n; j++){
            for(i=0; i<n; i++){
                c += q[i][j];
            }
            if(c!=s){
                cout<<"-1\n";
                c=-1;
                break;
            }
            c=0;
        }
        if(c==-1){
            break;
        }

        for(i=0; i<n; i++){
            d1 += q[i][i];
            d2 += q[i][n-1-i];
        }
        if(d1!= s or d2!=s){
            cout<<"-1\n";
            break;
        }
        cout<<s<<endl;
        break;
    }
    return 0;
}
