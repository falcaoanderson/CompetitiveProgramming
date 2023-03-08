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

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

void solve(){
    int a, b, c;

    cin >> a >> b >> c;

    int op1 = min(a, b/2);
    int op2 = min(b, c/2);

    int stones = max(op1 + min(b-op1*2, c/2), op2 + min(a, (b-op2)/2)) * 3;

    cout << stones << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
