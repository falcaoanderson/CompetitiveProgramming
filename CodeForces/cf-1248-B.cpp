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
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int x=0, y=0;
    for(int i=0; i<n/2; i++){
        x += v[i];
        y += v[n-i-1];
    }
    if(n&1) y+=v[n/2];

    cout << x*x + y*y << endl;;
}

int32_t main(){
    fastio;

    solve();

    return 0;
}
