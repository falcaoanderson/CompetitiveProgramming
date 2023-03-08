#include <iostream>
using namespace std;

int main(){
    short int n,i,j,x;
    int maior=0,temp=0;
    cin>>n;
    int matriz[n][n];


    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>> matriz[i][j];
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(x=0; x<n; x++){
                temp+= matriz[x][j];
                temp+= matriz[i][x];
            }
            temp-= matriz[i][j]*2;
            if(temp>maior){
                maior=temp;
            }
            temp=0;
        }
    }

    cout<<maior<<endl;
    return 0;
}

