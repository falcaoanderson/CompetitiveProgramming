/*
28/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int> psum(n), minp(n);
    for(int i=0; i<n; i++){
        psum[i] = (s[i]=='B'? 1: -1);
        if(i>0) psum[i] += psum[i-1];
    }

    for(int i=n-1; i>=0; i--){
        minp[i] = (s[i]=='B'? 1: -1);
        
        if(i < n-1) minp[i] += min(0, minp[i+1]);
    }

    // for(int x: psum) cout << x << " "; 
    // cout << endl;
    // for(int x: minp) cout << x << " "; 
    // cout << endl;

    if(minp[0] >= 0){
        cout << 0 << endl;
        return;
    }

    for(int i=0; i<n-1; i++){
        if(minp[i+1]>=0 && psum[n-1]-psum[i]+minp[0]>=0){
            cout << i+1 << endl;
            return;
        }
    }

    cout << -1 << endl;
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