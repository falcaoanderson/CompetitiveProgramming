// 07/06/20 // 9:36 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, p, atual, ant;

    cin >> n >> p;

    int resp = 0;
    ant = 0;

    cin >> atual;
    resp = max(resp, atual-1);
    ant = atual;
    p--;

    while(p--){
        cin >> atual;

        resp = max(resp, (atual-ant-1)/2 + (atual-ant-1)%2);

        ant = atual;
    }
    resp = max(resp, n-ant);

    cout << resp << endl;

    return 0;
}
