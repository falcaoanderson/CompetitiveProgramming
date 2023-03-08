// 00/01/20 // 00:00 XM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define int long long

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    cout << (n-l-1 + (1<<l)) << " " << (1<<r) -1 + (n-r)*(1<<(r-1)) << endl;
}

int32_t main(){
    fastio;


    solve();

    return 0;
}
