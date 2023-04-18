// 17/04/22 //

#include <iostream>
 
using namespace std;
 
#define ll long long
 
const ll MOD = 1e9+7;
 
ll expo(ll a, int b){
    if(b==0) return 1LL;
    
    if(b%2LL==1LL){
        return (a*expo(a, b-1))%MOD;
    }
    
    return expo((a*a)%MOD, b/2)%MOD;
}
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        int a, b;
        cin >> a >> b;
        
        cout << expo(a, b) << endl;
    }
    
    return 0;
}