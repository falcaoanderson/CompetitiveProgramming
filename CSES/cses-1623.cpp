// 06/10/20 // 8:53 PM //

#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> peso(n, 0);
    int total=0;

    for(int i=0; i<n; i++){
        cin >> peso[i];
        total += peso[i];
    }

    int resp = INF;

    for(int mask=0; mask<(1<<n); mask++){
        int tsum = 0;

        for(int i=0; i<n; i++)
            if((mask&(1<<i))!=0) tsum += peso[i];

        resp = min(resp, abs(2*tsum - total));
    }

    cout << resp << endl;

    return 0;
}

