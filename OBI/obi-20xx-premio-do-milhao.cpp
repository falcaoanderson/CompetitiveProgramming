// 11/06/20 // 10:56 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, sum=0, resp=0;

    cin >> n;

    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;

        sum += temp;

        if(sum>=1000000 && resp==0){
            resp = i;
        }
    }

    cout << resp << endl;

    return 0;
}
