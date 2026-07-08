/*
14/02/26 

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

int main(){
    fast_io;

    int n, d;
    cin >> n >> d;

    vector<int> maxval((1<<d)-1, -INF), minval((1<<d)-1, INF);

    for(int i=0; i<n; i++){
        vector<int> v(d);
        for(int i=0; i<d; i++) cin >> v[i];
        
        for(int mask=0; mask<=(1<<d)-2; mask++){
            int val = 0;

            for(int k=0; k<d; k++){
                val += (((mask&(1<<k)) != 0)? -v[k]: v[k]);
            }

            maxval[mask] = max(maxval[mask], val);
            minval[mask] = min(minval[mask], val);
        }
    }

    int ans = -INF;
    for(int mask=0; mask<=(1<<d)-2; mask++){
        ans = max(ans, maxval[mask] - minval[mask]);
    }

    cout << ans << endl;

    return 0;
}
