// 26/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;
const ll MOD  = (1e4) + 7;

ll n, fat[MAXN], inv[MAXN], memo[MAXN][MAXN];
bool v[MAXN];

ll exp(ll a, ll b, ll m=MOD){
    if(b==0) return 1LL;

    if(b&1) return (a*exp(a, b-1, m))%m;
    return exp((a*a)%m, b/2, m)%m;
}

void ini(){
    ll limite = MAXN-10;

    fat[0] = 1LL;
    for(ll i=1LL; i<=limite; i++) fat[i] = (i * fat[i-1])%MOD;

    inv[limite] = exp(fat[limite], MOD-2); 
    for(ll i=limite-1; i>=0; i--) inv[i] = (inv[i+1] * (i+1LL))%MOD;
}

ll comb(ll a, ll b){
    if(b>a) return 0LL;

    return ( fat[a] * ((inv[b] * inv[a-b])%MOD) )%MOD;
}

/*
ll solve(int l, int r){
    if(memo[l][r] != -1) return memo[l][r];

    if(l==r){
        if(l==1 || l==n) 
            return (v[l] == 0);
        else 
            return (v[l] == 1);
    }

    ll& ans = memo[l][r] = 0LL;

    if( (v[l]==1 && l==1) || (v[l]==0 && l>1) ){
        ans += solve(l+1, r)%MOD;
        ans %= MOD;
    }
    if( (v[r]==1 && r==n) || (v[r]==0 && r<n) ){
        ans += solve(l, r-1)%MOD;
        ans %= MOD;
    }

    for(int i=l+1; i<=r-1; i++)
        if(v[i]==1){
            ans += ( solve(l, i-1) * (( solve(i+1, r) * comb(r-l, i-l) )%MOD) )%MOD;
            ans %= MOD;
        }
    
    return ans;
}
*/

int main(){ 
    fast_io;

    cin >> n;
    for(int i=1; i<=n; i++){
        char c; cin >> c;

        v[i] = (c=='P');
    }   

    if(n==1){
        cout << (v[1]==1) << endl;
        return 0;
    }

    ini();

    //memset(memo, -1, sizeof(memo));
    //cout << solve(1, n) << endl;


    memo[1][1] = (v[1]==0);
    memo[n][n] = (v[n]==0);
    for(int i=2; i<=n-1; i++) memo[i][i] = (v[i]==1);


    for(int t=2; t<=n; t++){
        for(int l=1; l<=n && l+t-1<=n; l++){
            int r = l+t-1;

            ll& ans = memo[l][r] = 0LL;

            if( (v[l]==1 && l==1) || (v[l]==0 && l>1) ){
                ans += memo[l+1][r];
                ans %= MOD;
            }
            if( (v[r]==1 && r==n) || (v[r]==0 && r<n) ){
                ans += memo[l][r-1];
                ans %= MOD;
            }

            for(int i=l+1; i<=r-1; i++)
                if(v[i]==1){
                    ans += ( memo[l][i-1] * (( memo[i+1][r] * comb(r-l, i-l) )%MOD) )%MOD;
                    ans %= MOD;
                }
        }
    }

    cout << memo[1][n] << endl;

    return 0;
}
