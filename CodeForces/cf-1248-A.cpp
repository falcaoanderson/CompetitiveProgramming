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
    int n, p1=0, i1=0, p2=0, i2=0;

    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        p1 += ~temp&1;
        i1 +=  temp&1;
    }

    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        p2 += ~temp&1;
        i2 +=  temp&1;
    }

    cout << p1*p2 + i1*i2 << endl;
}

int32_t main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
