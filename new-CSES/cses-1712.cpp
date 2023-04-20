// 20/04/23 //
#include <iostream>
 
using namespace std;
 
#define ll long long
 
const ll MOD = 1e9+7;
 
ll expo(ll a, ll b, ll mod=MOD){
    if(b==0LL) return 1LL;
    
    if(b&1LL){
        return (a*expo(a, b-1LL, mod))%mod;
    }
    
    return expo((a*a)%mod, b/2LL, mod)%mod;
}
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        
        cout << expo(a, expo(b, c, MOD-1), MOD) << endl;
    }
    
    return 0;
}