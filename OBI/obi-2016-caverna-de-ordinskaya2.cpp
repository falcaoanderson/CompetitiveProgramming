#include <iostream>
using namespace std;

int main(){
    long long n,m,i,r=0,t;
    cin>>n>>m;
    long long v1[n],v2[n];

    for(i=0; i<n; i++){
        cin>>v1[i];
        v2[i]= (m - v1[i]);
        cout<<i<<" -> "<<v1[i]<<" - "<<v2[i]<<endl;
    }

    for(i=0; i<n; i++){
        cout<< endl << "I = "<< i <<endl;
        if(i==0){
            if (v1[i]<=v2[i]){
                r+=v1[i];
                t =v1[i];
                cout<<"TESTE "<<i+1<< " --> "<< t << " "<< r <<endl;
            }
            else{
                r+=v2[i];
                t =v2[i];
                cout<<"TESTE "<<i+1<< " --> "<< t << " "<< r <<endl;
            }
        }

        else if(i==n-1){
            if(v1[i]<=v2[i] and v1[i]>=t){
                r+=v1[i];
            }else if(v2[i]<v1[i] and v2[i]>=t){
                r+=v2[i];
            }else if(v1[i]>v2[i] and v1[i]>=t){
                r+=v1[i];
                cout<<"TESTE "<<i+1<< " --> "<< t << " "<< r <<endl;
            }else if(v2[i]>=v1[i] and v2[i]>=t){
                r+=v2[i];
                cout<<"TESTE "<<i+1<< " --> "<< t << " "<< r <<endl;
            }else{r=-1;}
            break;
        }
        else if(v1[i]<=v2[i] and v1[i]>=t){
            r+=v1[i];
            t =v1[i];
            cout<<"TESTE "<<i+1<< " --> "<< t << " "<< r <<endl;
        }else if(v2[i]<v1[i] and v2[i]>=t){
            r+=v2[i];
            t =v2[i];
            cout<<"TESTE "<<i+1<< " --> "<< t << " "<< r <<endl;
        }else if(v1[i]>v2[i] and v1[i]>=t){
            r+=v1[i];
            t =v1[i];
            cout<<"TESTE "<<i+1<< " --> "<< t << " "<< r <<endl;
        }else if(v2[i]>v1[i] and v2[i]>=t){
            r+=v2[i];
            t =v2[i];
            cout<<"TESTE "<<i+1<< " --> "<< t << " "<< r <<endl;
        }else{
            r=-1;
            break;
        }
    }
    cout<<r<<endl;
    return 0;
}
