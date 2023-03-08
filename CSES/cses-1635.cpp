// 31/10/20 // xx:xx PM //
 
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
const int MAXV = (1e6) + 10;
const int MOD = (1e9) + 7;
 
int main(){
    fast_io;
 
    int n, x;
    cin >> n >> x;
 
    vector<int> coin(n+1);
    vector<ll> memo(x+1);
 
    for(int i=1; i<=n; i++) cin >> coin[i];
 
    memo[0] = 1LL;
 
    for(int val=1; val<=x; val++){
        for(int i=1; i<=n; i++){
 
            if(val>=coin[i]) memo[val] = (memo[val] + memo[val-coin[i]])%MOD;
        }
    }
    
    cout << memo[x] << endl;
 
    return 0;
}