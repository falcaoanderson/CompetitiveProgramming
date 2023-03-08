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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, lista[1000];

    while(true){
        cin >> lista[0];
        if(lista[0]==-1) break;

        for(int i=1; i<1000; i++) cin>>lista[i];

        cin>>num;
        cout<< num <<" appeared " << contador(lista,num)<<" times\n";
    }

    return 0;
}
