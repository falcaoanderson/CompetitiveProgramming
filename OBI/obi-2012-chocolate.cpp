// 11/10/20 // 3:53 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){

    double n;
    cin >> n;

    long long resp = 1;

    while(n>=2){
        resp *= 4;
        n = n/2;
    }

    cout << resp << endl;

    return 0;
}
