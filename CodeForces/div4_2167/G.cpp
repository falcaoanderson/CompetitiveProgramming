/*
28/10/25 

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
const int MAXN = (8e3) + 5;
const int MOD  = (1e9) + 7;

ll memo[MAXN][5];
int v[MAXN], c[MAXN];

void solve(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) cin >> v[i];
    for(int i=1; i<=n; i++) cin >> c[i];
    v[n+1] = INF;

    for(int j=0; j<=n+1; j++){
        for(int i=0; i<2; i++){
            memo[j][i] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n+1; j++){
            if(v[i] <= v[j]){
                memo[j][i%2] = min(memo[i][(i-1)%2], memo[j][(i-1)%2] + (ll)c[i]); // mantem v[i] ou aumenta para v[j]
            }
            else{
                memo[j][i%2] = memo[j][(i-1)%2] + (ll)c[i]; // diminui para v[j]
            }
        }
    }

    cout << memo[n+1][n%2] << endl;
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
