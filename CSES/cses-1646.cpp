// 30/05/20 // 6:31 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const int MAXN = (int)(2e5) + 10;

int n, q, prefix[MAXN];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i=1; i<=n; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << prefix[b] - prefix[a-1] << endl;
    }

    return 0;
}
