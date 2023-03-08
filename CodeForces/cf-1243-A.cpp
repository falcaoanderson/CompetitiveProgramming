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
const int MAXN = (int)(1e5) + 10;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& i: v)cin >> i;
    sort(v.begin(), v.end());

    int resp = 1;
    for(int i=n-1; i>=0; i--){
        resp = max(resp, min(n-i, v[i]));
    }
    cout << resp << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
