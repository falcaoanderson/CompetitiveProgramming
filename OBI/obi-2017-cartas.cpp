// 27/07/20 // 11:31 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;

    cin >> a >> b >> c;

    if(a==b) cout << c << endl;
    if(a==c) cout << b << endl;
    if(b==c) cout << a << endl;

    return 0;
}

