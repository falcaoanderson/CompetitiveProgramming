#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int v[100005],n;
    cin>> n;

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v,v+n);

    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    return 0;
}