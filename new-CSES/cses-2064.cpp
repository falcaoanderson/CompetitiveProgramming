/*
23/01/26

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
const int MAXN = 1e5 + 5;
const ll MOD = 1e9+7;
 
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
 
    ll n;
    cin >> n;
 
    if(n&1LL){
        cout << 0 << endl;
        return 0;
    }
    else{
        n /= 2LL;
    }
 
    ll resp = exp(n+1, MOD-2LL), fat = 1;
    for(ll i=1; i<=2LL*n; i++){
        fat = (fat * i) % MOD;
 
        if(i==n){
            resp = (resp * exp((fat * fat)%MOD, MOD-2LL)) % MOD;
        }
    }
    resp = (resp * fat) % MOD;
 
    cout << resp << endl;
 
    return 0;
