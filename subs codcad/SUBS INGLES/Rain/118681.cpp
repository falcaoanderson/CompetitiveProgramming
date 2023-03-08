#include <iostream>
using namespace std;

int main(){
    int n,i,j;
    cin>> n;
    int ma[n][n], mb[n][n];

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>>ma[i][j];
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>>mb[i][j];
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            ma[i][j]= ma[i][j]+ mb[i][j];
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<ma[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}
