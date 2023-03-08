// 11/10/20 // 4:08 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){

    int a, b, c;
    cin >> a >> b >> c;
    cout << min(a/2, min(b/3, c/5)) << endl;

    return 0;
}
