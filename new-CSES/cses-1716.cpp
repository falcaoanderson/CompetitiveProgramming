// 23/04/23 //
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
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
const ll MOD = 1e9+7;
 
ll expo(ll a, ll b, ll mod=MOD){
    if(b==0LL) return 1LL;
    
    if(b&1LL){
        return (a*expo(a, b-1LL, mod))%mod;
    }
    
    return expo((a*a)%mod, b/2LL, mod)%mod;
}
ll fat(ll n){
    if(n==0) return 1;
    
    return (n*fat(n-1))%MOD;
}
ll ifat(ll n){
    return expo(fat(n), MOD-2,MOD);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    cout << (((fat(n+m-1)*ifat(n-1))%MOD)*ifat(m))%MOD << endl;
    
    return 0;
}
