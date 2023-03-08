#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,i;
    double k;
    cin>>n;

    cout.precision(4);
    cout.setf(ios::fixed);

    for(i=0; i<n; i++){
        cin>>k;
        cout<< sqrt(k)<< endl;
    }

    return 0;
}