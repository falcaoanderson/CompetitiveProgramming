#include <iostream>
using namespace std;

int k[10010];

int main(){
    int p, s, u, v;

    cin >> p >> s;

    int i,j;

    for(i=0; i<s; i++){
        cin >> u >> v;
        for(j=u; j<v; j++){
            k[j]=1;
        }
    }

    if(k[0]==1){cout << 0 << " ";}

    for(i=1; i<=p; i++){
        if(k[i]==1 and k[i-1]==0){
            cout << i << " ";
        }
        if(k[i]==1 and k[i+1]==0){
            cout << i+1 << endl;
        }
    }

    return 0;
}
