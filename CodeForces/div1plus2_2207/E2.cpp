 /*
13/03/26 

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
const ll MOD  = (1e9) + 7;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int qnt = 0, top = n-1;
    ll count_a = 1LL, count_b = 1LL;
    vector<pii> va;

    for(int i=0; i<n; i++){
        while(top > a[i]){
            va.PB({top, qnt});
            top--;
        }
        if(top == a[i]) top--;
    
        if((i == 0 && a[0] == n) || a[i] == a[i-1]){
            qnt++;
        }        
        else{
            count_b = (count_b * (ll)(i + 1)) % MOD;
        }
    }
    
    while(top >= 0){
        va.PB({top, qnt});
        top--;
    }

    for(int i = 0; i < SZ(va); i++){
        count_a = (count_a * (ll)(va[i].SS - i)) % MOD;
    }

    cout << (count_a * count_b) % MOD << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
