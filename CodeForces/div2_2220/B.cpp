/*
13/04/26 

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

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int cnt = 1;
    bool ans = 1;
    for(int i=1; i<n; i++){
        if(a[i] == a[i-1]){
            cnt++;
        }
        else{
            cnt = 1;
        }

        if(cnt == m){
            ans = 0;
            break;
        }
    }
    
    cout << (ans? "YES": "NO") << endl;
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
