#include <iostream>
using namespace std;
#define MAXN 100005

int main(){
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
        for(x; x<=y; x++){
            swap(cima[x],baixo[x]);
        }
    }

    for(int i=0; i<n; i++){
        cout << cima[i] << " ";
    }
    cout<<endl;
    return 0;
}
