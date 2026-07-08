/*
26/02/26 

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
    int n, m;
    cin >> n >> m;

    int maxb = 0;
    vector<int> va(n), vb(m);
    for(int i=0; i<n; i++) cin >> va[i];
    for(int i=0; i<m; i++){
        cin >> vb[i];
        maxb = max(maxb, vb[i]);
    }

    sort(va.begin(), va.end());
    vector<int> count(maxb+1);
    int aux = 1;
    for(int i=0; i<n; i++){
        if(i==n-1 || va[i] < va[i+1]){
            for(int j=va[i]; j<=maxb; j+=va[i]){
                count[j] += aux;
            }
            aux = 1;
        }
        else{
            aux++;
        }
    }

    int q1 = 0, q2 = 0, q3 = 0;
    for(int i=0; i<m; i++){
        if(count[vb[i]] == 0){
            q2++;
        }
        else if(count[vb[i]] < n){
            q3++;
        }
        else{
            q1++;
        }
    }

    if(q3&1){
        q1++;
    }

    cout << (q1 > q2? "Alice": "Bob") << endl;
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
