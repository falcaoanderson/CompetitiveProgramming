#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int doces,v[3];

    cin>>doces;

    for(int i=0; i<3;i++){
        cin>>v[i];
    }

    int cont=0;
    sort(v,v+3);
    for(int i=0; i<3;i++){
        if(doces-v[i]>=0){
            cont++;
            doces-=v[i];
        }else{break;}
    }

    cout<<cont<<endl;

    return 0;
}