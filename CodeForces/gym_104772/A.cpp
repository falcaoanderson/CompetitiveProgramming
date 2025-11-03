/*
18/10/25

*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v(4);
    for(int i=0; i<4; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int resp = v[0] * v[2];

    cout << resp << endl;

    return 0;
}