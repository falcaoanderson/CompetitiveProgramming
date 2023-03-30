// 30/03/23 //
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define endl "\n"

typedef long long ll;

inline int abs(int a){
    return (a>0 ? a: -a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> v(n, 0);
    
    for(int i=0; i<n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());

    int med = v[n/2];
    ll resp = 0;

    for(int i=0; i<n; i++) 
        resp += (ll)abs(v[i]-med);

    cout << resp << endl;

    return 0;
}