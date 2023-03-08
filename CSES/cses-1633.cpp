// 31/10/20 // 3:24 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e6) + 10;
const int MOD = (1e9) + 7;

ll memo[10];

int main(){
    fast_io;

    int n;
    cin >> n;

    memo[0] = 1;
    for(int i=1; i<=n; i++){
        memo[i%7] = memo[(i-1)%7]%MOD;
        if(i>=2) memo[i%7] = (memo[i%7]+memo[(i-2)%7])%MOD;
        if(i>=3) memo[i%7] = (memo[i%7]+memo[(i-3)%7])%MOD;
        if(i>=4) memo[i%7] = (memo[i%7]+memo[(i-4)%7])%MOD;
        if(i>=5) memo[i%7] = (memo[i%7]+memo[(i-5)%7])%MOD;
        if(i>=6) memo[i%7] = (memo[i%7]+memo[(i-6)%7])%MOD;
    }
    
    cout << memo[n%7] << endl;

    return 0;
}
