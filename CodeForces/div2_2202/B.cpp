/*
23/02/26 

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
    string s;
    cin >> n >> s;

    vector<vector<bool>> memo(n+1, vector<bool>(3, 0));
    if(n&1){
        memo[0][1] = 1;
    } 
    else{
        memo[0][0] = 1;
    }

    for(int i=1; i<=n; i++){
        if(s[i-1] == 'a'){
            memo[i][0] = memo[i-1][1];
            memo[i][1] = 0;
            memo[i][2] = memo[i-1][0];
        }
        if(s[i-1] == 'b'){
            memo[i][0] = memo[i-1][2];
            memo[i][1] = memo[i-1][0];
            memo[i][2] = 0;
        }
        if(s[i-1] == '?'){
            memo[i][0] = memo[i-1][1] || memo[i-1][2];
            memo[i][1] = memo[i-1][0];
            memo[i][2] = memo[i-1][0]; 
        }
    }

    if(memo[n][0] || memo[n][1] || memo[n][2]) cout << "YES" << endl;
    else cout << "NO" << endl;
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
