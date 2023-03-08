#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){

    int w;
    cin >> w;

    bool ok = false;
    for(int i=2; i<w; i++)
        if(~i&1 && ~(w-i)&1) ok = true;

    cout << (ok?"YES":"NO") << endl;

    return 0;
}
