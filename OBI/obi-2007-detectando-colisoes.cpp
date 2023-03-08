// 13/10/20 // 5:25 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){

    int xi[5], xf[5], yi[5], yf[5];

    cin >> xi[0] >> yi[0] >> xf[0] >> yf[0];
    cin >> xi[1] >> yi[1] >> xf[1] >> yf[1];

    if(xf[0]<xi[1] ||xi[0]>xf[1] || yf[0]<yi[1] ||yi[0]>yf[1])
        cout << 0 << endl;
    else
        cout << 1 << endl;

    return 0;
}
