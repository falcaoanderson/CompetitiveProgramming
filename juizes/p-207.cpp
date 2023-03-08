#include <iostream>
using namespace std;

int main(){
    int n,m,volta=0,tempo=0,menor,vencedor;

    cin>> n >> m;

    for(int i=1; i<=n; i++){
        for(int k=0; k<m; k++){
            cin>>volta;
            tempo+=volta;
        }
        if(tempo<menor or i==1){
            menor = tempo;
            vencedor = i;
        }
        tempo = 0;
    }
    cout<<vencedor;
    return 0;
}
