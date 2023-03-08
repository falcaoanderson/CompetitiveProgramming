#include <bits/stdc++.h>

using namespace std;

int main(){
    int b, t;
    cin >> b >> t;

    if( (b+t) == 160 )
        cout << "0\n";
    else if(b+t > 160)
        cout << "1\n";
    else
        cout << "2\n";

    return 0;
}
