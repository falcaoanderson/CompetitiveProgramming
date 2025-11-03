/*
23/10/25 

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

int main(){
    fast_io;

    ll n;
    cin >> n;

    ll resp = 0;
    for(ll i=2; 2*i<=n; i++){
        ll q = (n-i) / i;

        resp += (q * (q+3LL)) / 2LL;
    }

    cout << resp * 4LL << endl;

    return 0;
}