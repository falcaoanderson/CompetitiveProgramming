// 24/04/23 // dp
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
 
const int MOD = 1e9+7;
const int MAXN = 5e2 + 5;
const int MAXVAL = 62625 + 5;

int solve[MAXN][MAXVAL];

ll expo(ll a, ll b, ll mod=MOD){
    if(b==0LL) return 1LL;
    
    if(b&1LL){
        return (a*expo(a, b-1LL, mod))%mod;
    }
    
    return expo((a*a)%mod, b/2LL, mod)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;

    int sum = (n*(n+1))/2;

    if(sum&1){
        cout << 0 << endl;
        return 0;
    }

    sum /= 2;

    // solve[i][val] = quantas formas eh possivel formar val com os i primeiros numeros

    solve[0][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            solve[i][j] = solve[i-1][j];

            if(j>=i) solve[i][j] = (solve[i][j] + solve[i-1][j-i])%MOD;
        }
    }

    cout << (solve[n][sum] * expo(2, MOD-2, MOD))%MOD << endl;

    return 0;
}