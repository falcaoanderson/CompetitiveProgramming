/*
22/10/25 

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
const int MAXN = (1e6) + 5;
const int MOD  = (1e9) + 7;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    ll resp = 0;

    for(int i=0; i<n; i++){
        cin >> v[i];

        if(i&1){
            resp -= (ll)v[i];
        }
        else{
            resp += (ll)v[i];
        }
    }

    int delta = (n&1? n-1: n-2);

    int aux = -INF;
    for(int i=2; i<n; i+=2){
        aux = max(aux, 2*v[i-1] - (i-1));

        delta = max(delta, aux - (2*v[i] - i));
    }

    aux = -INF;
    for(int i=(n&1? n-3: n-2); i>=0; i-=2){
        aux = max(aux, 2*v[i+1] + (i+1));

        delta = max(delta, aux - (2*v[i] + i));
    }

    cout << resp + (ll)delta << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    
    return 0;
}
