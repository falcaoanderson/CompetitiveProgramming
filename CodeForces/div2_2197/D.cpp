/*
12/02/26 

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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int sq = ceil(sqrt(n)), ans = 0;

    for(int i=0; i<n; i++){
        if(v[i] <= sq){
            for(int k=1; k<=sq && i+k*v[i]<n; k++){
                ans += (v[i + k*v[i]] == k);
            }
        }
        else{
            for(int k=1; i+k*v[i]<n; k++){
                ans += (v[i + k*v[i]] == k);
            }
            for(int k=-1; i+k*v[i]>=0; k--){
                ans += (v[i + k*v[i]] == -k);
            }
        }
    }

    cout << ans << endl;
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
