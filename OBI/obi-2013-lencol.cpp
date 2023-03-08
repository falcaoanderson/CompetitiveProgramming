// 12/06/20 // 7:55 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a1, b1, a2, b2, a, b;

    cin >> a1 >> b1 >> a2 >> b2 >> a >> b;

    int x[5], y[5];

    x[1] = b1+a2;
    y[1] = min(a1, b2);

    x[2] = b1+b2;
    y[2] = min(a1, a2);

    x[3] = a1+a2;
    y[3] = min(b1, b2);

    x[4] = a1+b2;
    y[4] = min(b1, a2);

    bool resp = false || (a1>=a && b1>=b) ||(a1>=b && b1>=a)
                      || (a2>=a && b2>=b) ||(a2>=b && b2>=a);

    for(int i=1; i<=4; i++){
        if((x[i]>=a && y[i]>=b) || (x[i]>=b && y[i]>=a)) resp = true;
    }

    cout << (resp?"S":"N") << endl;

    return 0;
}

