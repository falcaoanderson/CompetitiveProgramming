#include <iostream>
using namespace std;
#define MAXN 100005

int aux[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,t,x,y;
    int cima[MAXN],baixo[MAXN];


    cin >> n >> t;
    for(int i=0; i<n; i++){
        cin >> cima[i];
    }
    for(int i=0; i<n; i++){
        cin >> baixo[i];
    }

    for(int i=0; i<t; i++){
        cin >> x >> y;
        x--;
        y--;
        for(x=x; x<=y; x++){
            aux[x]+=1;
        }
    }

    for(int i=0; i<n; i++){
        if(aux[i]%2==0){
            cout << cima[i] <<" ";
        }else{
            cout << baixo[i] << " ";
        }
    }
    cout<<"\n";

    return 0;
}
