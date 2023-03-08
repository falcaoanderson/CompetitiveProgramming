#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    cout << n << " ";
    while(n!=1){
        n = n&1? 3*n+1: n/2;
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
