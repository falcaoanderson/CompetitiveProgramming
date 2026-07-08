/*
27/02/26 

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
const int MAXN = (5e5) + 5;
const int MOD  = (1e9) + 7;

int calc(int l, int r, vector<vector<int>> &st, vector<int> &v){
    if(r-l <= 1) return 0;
    
    int len = r - l + 1, loglen = 0;
    while(len / 2 > 0) {loglen++; len /= 2;}
    int max_idx = l-1;
    if(v[st[l][loglen]] > v[st[r-(1<<loglen)+1][loglen]]){
        max_idx = st[l][loglen];
    }
    else{
        max_idx = st[r-(1<<loglen)+1][loglen];
    }

    return min(max_idx-l + calc(max_idx+1, r, st, v), r-max_idx + calc(l, max_idx-1, st, v));
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<int>> st(n, vector<int>(25));
    
    for(int i=0; i<n; i++){
        cin >> v[i];
        st[i][0] = i;
    }

    for(int k=1; (1<<k) <= n; k++){
        for(int i=0; i + (1<<k) - 1 < n; i++){
            if(v[st[i][k-1]] > v[st[i + (1<<(k-1))][k-1]]){
                st[i][k] = st[i][k-1];
            }
            else{
                st[i][k] = st[i + (1<<(k-1))][k-1];
            }
        }
    }

    cout << calc(0, n-1, st, v) << endl;
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
