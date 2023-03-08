// 09/06/20 // 9:59 PM //

#include <bits/stdc++.h>

using namespace std;

int v[10];

int main(){
    for(int i=0; i<4; i++) cin >> v[i];
    sort(v, v+4);

    if(v[0]+v[1]>v[2] || v[1]+v[2]>v[3] || v[0]+v[1]>v[3] || v[0]+v[2]>v[3]) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}
