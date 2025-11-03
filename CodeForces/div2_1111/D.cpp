/*
16/10/25 

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
const int MAXK = 52;
const ll MOD  = (1e9) + 7;

int qnt[MAXK+5];

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

inline int code(char c){
    return (c>'Z'? c-'a': c-'A'+26);
}

ll compute_constfactor(int n){
    vector<ll> fat(2*n+1), ifat(2*n+1);  

    fat[0] = 1;
    for(int i=1; i<=2*n; i++){
        fat[i] = ((ll)i * fat[i-1]) % MOD;
    }

    ifat[2*n] = exp(fat[2*n], MOD-2LL);
    for(int i=2*n-1; i>=0; i--){
        ifat[i] = (ifat[i+1] * (ll)(i+1)) % MOD;
    }

    ll constfactor = (fat[n] * fat[n]) % MOD;

    for(int k=0; k<MAXK; k++){
        constfactor *= ifat[qnt[k]];
        constfactor %= MOD;
    }

    return constfactor;
}

int main(){
    fast_io;

    string s;
    cin >> s;
    int n = SZ(s)/2;

    for(char c: s){
        qnt[code(c)]++;
    }

    ll constfactor = compute_constfactor(n);
    // cout << "constante: " << constfactor << endl;
    vector<ll> memo(n+1);

    memo[0] = 1;
    for(int k=0; k<MAXK; k++){ // 52
        if(qnt[k]==0) continue;
        for(int val=n; val>=qnt[k]; val--){ // 10^5 / 2
            memo[val] += memo[val-qnt[k]];
            memo[val] %= MOD;
        }
    }
    // cout << "dp n: " << memo[n] << endl;

    vector<vector<ll>> resp(55, vector<ll>(55));

    for(int x=0; x<MAXK; x++){ // K
        if(qnt[x]==0) continue;
        // cout << "x: " << x << endl;

        for(int val=qnt[x]; val<=n; val++){ // N
            memo[val] = (memo[val] - memo[val-qnt[x]] + MOD) % MOD;
        }

        for(int y=0; y<=x; y++){ // K
            if(qnt[y]==0) continue;
            // cout << "y: " << y << endl;
            for(int val=qnt[y]; x!=y && val<=n; val++){ // N
                memo[val] = (memo[val] - memo[val-qnt[y]] + MOD) % MOD;
            }

            resp[x][y] = (memo[n] * constfactor ) % MOD;
            resp[x][y] = (resp[x][y] * 2LL) % MOD;

            // cout << "resp: " << resp[x][y] << endl;
            for(int val=n; x!=y && val>=qnt[y]; val--){ // N
                memo[val] += memo[val-qnt[y]];
                memo[val] %= MOD;
            }
        }
        // cout << endl;
        for(int val=n; val>=qnt[x]; val--){ // N
            memo[val] += memo[val-qnt[x]];
            memo[val] %= MOD;
        }
    }

    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;

        x = code(s[x-1]);
        y = code(s[y-1]);
        if(x<y) swap(x, y);

        cout << resp[x][y] << endl;
    }

    return 0;
}
