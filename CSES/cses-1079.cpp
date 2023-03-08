// 17/11/20 // 5:42 PM //

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
const int MAXN = (1e6);
const ll MOD  = (1e9) + 7;

int n;
ll fat[MAXN+5], inv[MAXN+5];

ll exp(ll a, ll b){
    if(b==0) return 1LL;

    if(b&1) return (a*exp(a, b-1))%MOD;
    return exp((a*a)%MOD, b/2)%MOD;
}

void ini(){
    fat[0] = 1LL;
    for(ll i=1LL; i<=MAXN; i++) 
        fat[i] = (i * fat[i-1])%MOD;

    inv[MAXN] = exp(fat[MAXN], MOD-2);

    for(ll i=MAXN-1LL; i>=0LL; i--)
        inv[i] = (inv[i+1] * (i+1LL))%MOD;
}

int main(){
    fast_io;

    ini();

    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;

        cout << (fat[a]*((inv[b]*inv[a-b])%MOD))%MOD << endl;
    }
    

    return 0;
}
