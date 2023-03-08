// 08/06/20 // 10:39 PM //

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

const int MAXN = (int)(2e5) + 10;
const int INF = 0x3f3f3f3f;

int n, h[MAXN], a[MAXN], dp[MAXN];

int query(int i){
    int qmax = 0;

    while(i>0){
        qmax = max(qmax, dp[i]);
        i -= (i&-i);
    }

    return qmax;
}

void update(int i, int val){
    while(i<=n){
        dp[i] = max(dp[i], val);
        i += (i&-i);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++) cin >> h[i];
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++){
        update(h[i], max(query(h[i]-1) + a[i], query(h[i])));
    }

    cout << query(n) << endl;

    return 0;
}
