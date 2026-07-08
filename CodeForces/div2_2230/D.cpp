/*
18/05/26 

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
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    vector<int> nxt_fail(n, -1), nxt_fail_path(n, -1), last_pos(n+2, -1);
 
    for(int i=n-1; i>=0; i--){
        last_pos[a[i]] = i;
        last_pos[b[i]] = i;

        if(a[i] == b[i] && a[i] == 1){
            int nxt = last_pos[a[i] + 1];

            if(nxt == -1){
                nxt_fail[i] = n;
            }
            else{
                if(a[nxt] != b[nxt]){
                    nxt_fail[i] = nxt;
                }
                else{
                    nxt_fail[i] = nxt_fail_path[nxt];
                }
            }
            nxt_fail_path[i] = nxt_fail[i];
        }
        else{
            int nxt_one = last_pos[1];

            if(nxt_one == -1){
                nxt_fail[i] = n;
            }
            else{
                if(a[nxt_one] != b[nxt_one]){
                    nxt_fail[i] = nxt_one;
                }
                else{
                    nxt_fail[i] = nxt_fail_path[nxt_one];
                }
            }

            if(a[i] == b[i]){
                int nxt = last_pos[a[i] + 1];

                if(nxt == -1){
                    nxt_fail_path[i] = n;
                }
                else{
                    if(a[nxt] != b[nxt]){
                        nxt_fail_path[i] = nxt;
                    }
                    else{
                        nxt_fail_path[i] = nxt_fail_path[nxt];
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += (ll)(nxt_fail[i] - i);
    }
    cout << ans << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
