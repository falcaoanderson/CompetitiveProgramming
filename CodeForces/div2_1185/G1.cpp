/*
15/10/25 

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

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

int memo[(1<<15)+5][225+5][5];

int main(){
    fast_io;

    int n, total;
    cin >> n >> total;

    vector<int> duration(n), gender(n);
    for(int i=0; i<n; i++){
        cin >> duration[i] >> gender[i];
        gender[i]--;
    }

    
    for(int mask=0; mask<(1<<n); mask++){
        memo[mask][0][0] = 1;
        memo[mask][0][1] = 1;
        memo[mask][0][2] = 1;
    }

    for(int mask=1; mask<(1<<n); mask++){        
        for(int d=1; d<=total; d++){
            for(int i=0; i<n; i++){
                if(((1<<i) & mask) != 0  && duration[i]<=d){
                    memo[mask][d][gender[i]] += memo[mask^(1<<i)][d-duration[i]][(gender[i]+1)%3];
                    memo[mask][d][gender[i]] %= MOD;
                    memo[mask][d][gender[i]] += memo[mask^(1<<i)][d-duration[i]][(gender[i]+2)%3];  
                    memo[mask][d][gender[i]] %= MOD;
                }
            }
        
        }
    }

    ll resp = 0;
    for(int i=0; i<3; i++){
        resp = (resp + memo[(1<<n)-1][total][i])%MOD;
    }

    ll LMOD = MOD;
    cout << (resp * exp(2, LMOD-2, LMOD)) % LMOD << endl;

    return 0;
}
