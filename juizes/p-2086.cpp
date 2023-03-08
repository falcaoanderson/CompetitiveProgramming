#include <iostream>
using namespace std;

int contador(int lista[1000], int num){
    int total=0;
    for(int i=0; i<1000; i++){
        if(lista[i]==num){
            total+=1;
        }
    }
    return total;
}

int main(){
    int lista[1000],num;
    bool x = false;

    while(true){
        for(int i=0; i<1000; i++){
            cin>>lista[i];
            if(i==0 and lista[i]==-1){x=true; break;}
        }

        if(x==true){break;}
        cin>>num;
        cout<< num <<" appeared " << contador(lista,num)<<" times"<<endl;
    }
    return 0;
}
