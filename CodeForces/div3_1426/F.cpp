/*
26/01/26

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
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

ll memo[MAXN][8][8];

ll exp(ll a, ll b, ll mod=MOD){
    if(b==0) return 1; // 0^0 = 1

    ll res = 1, aux = a;
    while(b > 0){
        if(b&1){
            res = (res * aux) % mod;
            b--;
        }
        else{
            aux = (aux * aux) % mod;
            b /= 2;
        }
    }

    return res;
}

int main(){
    fast_io;

    int n;
    cin >> n;

    string aux = " abc";
    int count = 0;

    for(int i=1; i<=n; i++){
        char c;
        cin >> c;
        
        count += (c=='?');

        memo[i-1][0][0] = 1;
        for(int j=0; j<=3; j++){    
            for(int k=0; k<=3; k++){
                memo[i][j][k] = memo[i-1][j][k];

                if(c == aux[j]){
                    memo[i][j][k] = (memo[i][j][k] + memo[i-1][j-1][k]) % MOD;
                }
                if(c == '?' && k > 0){
                    memo[i][j][k] = (memo[i][j][k] + memo[i-1][j-1][k-1]) % MOD;
                }
            }
        }
    }

    ll resp = 0;
    for(int i=0; i<=3; i++){
        resp = (resp + (memo[n][3][i] * exp(3, count - i)) % MOD) % MOD;
    }

    cout << resp << endl;

    return 0;
}