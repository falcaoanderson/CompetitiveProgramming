/*
25/04/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 14 + 5;
const int MAXMASK = (1<<14) + 5
const int MOD  = (1e9) + 7;

int adj[MAXN];
ll memo[MAXN][MAXN][MAXMASK];

ll dp(int u, int k, int mask){
    if(u < 0 || k <= 0){
        return (u+1==0 && k == 0 && mask == 0);
    }

    if(memo[u][k][mask] != -1LL) return memo[u][k][mask];
    
    ll &crr_memo = memo[u][k][mask];

    if(u+1 < k || k == 0 || (mask & (1<<u)) == 0) return crr_memo = 0;
    if(u+1 == k) return crr_memo = 1;


    for(int q=1; q<=k; q++){
        for(int prev_mask=0; prev_mask < (1<<(u-1)); prev_mask++){
            prev_mask |= (1<<(u-1));

            ll f = 1 << __builtin_popcount(mask & prev_mask);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a] |= (1<<b);
        adj[b] |= (1<<a);
    }
}

int main(){
    fast_io;

    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
