// 29/03/23 //
//solucao boa
#include <iostream>
#include <vector>
 
using namespace std;
 
#define endl "\n"

typedef long long ll;

inline ll max(ll a, ll b){
    return (a>b ? a : b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> v(n, 0);
    
    for(int i=0; i<n; i++) cin >> v[i];
    
    ll resp = v[0];

    for(int i=1; i<n; i++){
        v[i] += max(0, v[i-1]);

        resp = max(resp, v[i]);
    }
    
    cout << resp << endl;

    return 0;
}