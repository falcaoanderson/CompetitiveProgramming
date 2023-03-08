#include <iostream>
using namespace std;

int main(){
    char d;
    string n,m="";
    int i,t=0;



    while(true){
        cin>>d>>n;
        if(d=='0' and n=="0"){break;}

        for(i=0; i<n.size(); i++){
            if(n[i]!=d){
                m+=n[i];
            }
        }
        for(i=0; i<m.size(); i++){
            if(m[i]=='0' and t==0  and i!=m.size()-1){
                continue;
            }else{
                t=1;
                cout<<m[i];
            }
        }
        if (m==""){cout<<"0";}
        cout<<endl;
        t=0;
        m="";
    }

    return 0;
}