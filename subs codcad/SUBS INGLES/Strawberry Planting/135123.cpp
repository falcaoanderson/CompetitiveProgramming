#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;

    cout << max(n1*n2,n3*n4) << endl;

    return 0;
}


