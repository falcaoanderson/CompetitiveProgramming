// 31/05/20 // 7:37 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){

    long long l, n;
    cin >> l >> n;

    long long r = (l-n+1)*(l-n+1) + (n-1);

    cout << r << endl;

    return 0;
}
