/*
03/03/26 

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

ll comb(int a, int b, vector<ll> &fat){
    return (((fat[a] * exp(fat[b], MOD - 2)) % MOD) * exp(fat[a-b], MOD - 2)) % MOD;
}

int main(){
    fast_io;

    int n;
    string s;
    cin >> n >> s;
    
    int m = SZ(s), crr = 0;
    bool flag = 1;
    for(char c: s){
        crr += (c == '('? 1: -1);
        if(crr < 0){
            flag = 0;
            break;
        }
    }

    if(!flag || (n&1) || crr > n - m){
        cout << 0 << endl;
        return 0;
    }
    if(crr == n - m){
        cout << 1 << endl;
        return 0;
    }

    int a = (m + crr) / 2, x = n - m, y = n/2 - a;

    vector<ll> fat(x+1);
    fat[0] = 1;
    for(ll i = 1; i <= x; i++) fat[i] = (i * fat[i-1]) % MOD;

    cout << (comb(x, y, fat) - comb(x, y-1, fat) + MOD) % MOD << endl; 

    return 0;
}
