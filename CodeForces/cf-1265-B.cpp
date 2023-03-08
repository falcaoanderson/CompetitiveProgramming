// 00/00/20 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 10;

void solve(){
    int n;

    cin >> n;
    vector<pair<int, int>> v(n+1);

    for(int i=1; i<=n; i++){
        cin >> v[i].ff;
        v[i].ss = i;
    }

    sort(v.begin(), v.end());

    int left = MAXN, right=-MAXN;

    for(int i=1; i<=n; i++){
        int pos = v[i].ss;

        left  = min( left, pos);
        right = max(right, pos);

        cout << (right-left+1 == i);
    }
    cout << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
