// 17/11/20 // 8:17 PM //

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
const int MAXN = (2e6) + 10;
const int MOD  = (1e9) + 7;

ll fat[MAXN], inv[MAXN];

ll exp(ll a, ll b, ll m=MOD){
    if(b==0) return 1LL;

    if(b&1) return (a*exp(a, b-1, m))%m;
    return exp((a*a)%m, b/2, m)%MOD;
}
void ini(int maxval){
    fat[0] = 1;
    for(int i=1; i<=maxval; i++) 
        fat[i] = (i*fat[i-1])%MOD;

    inv[maxval] = exp(fat[maxval], MOD-2);
    for(int i = maxval-1; i>=0; i--) 
        inv[i] = (inv[i+1]*(i+1))%MOD; 
}


int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    ini(n+k-1);

    cout << (fat[n+k-1] * ((inv[n-1] * inv[k])%MOD))%MOD << endl;

    return 0;
}
