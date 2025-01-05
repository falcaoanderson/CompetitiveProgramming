/*
04/01/25 
CF 578 Div.2 B 
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];

    bool win = 0;

    for(int i=0; i<n; i++){
        if(i==n-1) {win=1;break;}

        if(h[i]+k >= h[i+1]){
            m += min(h[i], h[i] + k - h[i+1]);
        }
        else if(h[i]+k+m >= h[i+1]){
            m += h[i] + k - h[i+1];
        }
        else{
            break;
        }
    }

    cout << (win? "YES": "NO") << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
