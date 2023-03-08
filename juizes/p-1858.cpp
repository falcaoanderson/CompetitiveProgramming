#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int v[6];

    for(int i=0; i<6; i++){
        cin >> v[i];
    }
    sort(v,v+6);

    cout << v[0] << endl << v[5] <<endl;

    return 0;
}
