// 27/07/20 // 11:31 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double p, g, resp = 1000000;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> p >> g;

        p = (p*1000)/g;

        resp = min(resp, p);
    }

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << resp << endl;

    return 0;
}
