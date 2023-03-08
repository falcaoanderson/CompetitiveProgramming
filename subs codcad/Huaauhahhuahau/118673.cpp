#include <iostream>
using namespace std;

int main(){
    string risada,vog="";
    int i,n=0;

    cin>>risada;

    for (i=0;i<risada.size();i++){
        if (risada[i]=='a' or risada[i]=='e' or risada[i]=='i' or risada[i]=='o' or risada[i]=='u'){
            vog+=risada[i];
        }
    }

    for(i=0;i<vog.size();i++){
        if(vog[i]==vog[vog.size()-1-i]){
            n=1;
        }else{
            cout<<"N\n";
            n=0;
            break;
        }
    }
    if(n==1){
        cout<<"S\n";
    }
    return 0;
}
