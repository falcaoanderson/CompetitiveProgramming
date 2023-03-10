#include <iostream>
#include <cmath>
using namespace std;

int v[1010];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> v[i];

    int dif,cont=0;

    for(int i=0; i<n-1; i++){
        if(v[i]==m)continue;
        dif = m - v[i];
        v[i] += dif; v[i+1]+= dif;
        cont+= abs(dif);
    }

    cout << cont << endl;

    return 0;
}
