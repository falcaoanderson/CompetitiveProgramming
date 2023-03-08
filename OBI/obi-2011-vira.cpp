// 20/10/20 // 6:46 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

const int MAXN = (1e3) + 10;
const int MOD = 10007;

int n, v[MAXN];
int memo[MAXN][MAXN];
int fat[MAXN], inv[MAXN];

int exp(int a, int b){
    if(b==0) return 1;

    if(b&1) return (a*exp(a, b-1))%MOD;
    else    return exp((a*a)%MOD, b>>1)%MOD;
}

void ini(){
    fat[0] = inv[0] = 1;
    for(ll i=1; i<n; i++)
        fat[i] = (i*fat[i-1])%MOD;

    inv[n-1] = exp(fat[n-1], MOD-2);
    for(ll i=n-2; i>=0; i--)
        inv[i] = (inv[i+1]*(i+1LL))%MOD;
}

int comb(int a, int b){
    return (fat[a] * ((inv[b] * inv[a-b])%MOD))%MOD;
}

int solve(int l, int r){
    int& ans = memo[l][r];

    if(ans!=-1) return ans;

    if(l>r) return 1;
    if(l==r){
        if(l==1 || l==n) return v[l]==0;
        else             return v[l]==1;
    }

    ans = 0;
    if((v[l]==0 && l!=1) || (l==1 && v[l]==1)) // ponta esquerda
        ans = (solve(l+1, r))%MOD;
    if((v[r]==0 && r!=n) || (r==n && v[r]==1)) // ponta direita
        ans = (ans + solve(l, r-1))%MOD;

    for(int i=l+1; i<r; i++) // meio
        if(v[i]==1){
            ans += (solve(l, i-1)  *  ((solve(i+1, r)  * comb(r-l, i-l))%MOD) )%MOD;
            ans %= MOD;
        }
    return ans;
}

int32_t main(){
    fast_io;

    cin >> n;

    for(int i=1; i<=n; i++){
        char temp;
        cin >> temp;

        if(temp=='P') v[i] = 1;
    }
    
    if(n==1){
        cout << (v[1]==1) << endl;
        return 0;
    }

    ini();
    
    memset(memo, -1, sizeof(memo));
    
    cout << solve(1, n) << endl;

    return 0;
}
