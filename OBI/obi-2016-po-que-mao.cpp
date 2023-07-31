// 11/06/20 // 10:47 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<int> qnt(3);

    cin >> n;
    for(int i=0; i<3; i++) cin >> qnt[i];

    sort(qnt.begin(), qnt.end());

    int resp = 0;
    for(int i=0; i<3; i++){
        if(qnt[i]<=n){
            resp++;
            n -= qnt[i];
        }
    }

    cout << resp << endl;

    return 0;
}
