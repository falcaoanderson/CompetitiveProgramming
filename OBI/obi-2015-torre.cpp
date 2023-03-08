#include <iostream>
using namespace std;

int main(){
    short int n,i,j;
    int maior=0,temp=0,temp2=0;
    cin>>n;
    int matriz[n][n],linha[n],coluna[n];

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>> matriz[i][j];
        }
    }

    for(i=0; i<n; i++){
       for(j=0; j<n; j++){
        temp +=matriz[i][j];
        temp2+=matriz[j][i];
       }
        linha[i] =temp;
        coluna[i]=temp2;
        temp=0;
        temp2=0;
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            temp=linha[i]+coluna[j]-2*matriz[i][j];
            if(temp>maior){
                maior=temp;
            }
            temp=0;
        }
    }

    cout<<maior<<endl;
    return 0;
}
