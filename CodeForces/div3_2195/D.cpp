/*
15/02/26 

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

    vector<ll> f(n+1);
    for(int i=1; i<=n; i++){
        cin >> f[i];
    }

    if(n==2){
        cout << f[2] << " " << f[1] << endl;
        return;
    }

    vector<ll> A(n);
    for(int i=1; i<n; i++){
        A[i] = f[i+1] - f[i];
    }

    vector<ll> ans(n+1);
    for(int i=2; i<=n-1; i++){
        ans[i] = (A[i] - A[i-1]) / 2LL;
    }

    ans[n] = f[1];
    for(int i=2; i<=n-1; i++){
        ans[n] -= ans[i] * (ll)(i-1); 
    }
    ans[n] /= (ll)(n-1);

    ans[1] = ans[n] + (A[1] + A[n-1]) / 2LL;

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << endl; 
}

int main(){
    fast_io;

    int t;
    cin >> t;
    while(t--) solve(); 

    return 0;
}
