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
const int MAXN = 1e5 + 10;

void solve(){
    int n, min_r=INF, max_l=-INF;
    cin >> n;

    for(int i=0; i<n; i++){
        int l, r;
        cin >> l >> r;
        if(r<l) swap(l, r);

        min_r = min(min_r, r);
        max_l = max(max_l, l);
    }
    cout << max(max_l - min_r, 0) << endl;

}

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
