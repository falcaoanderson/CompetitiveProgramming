/*
17/09/25 

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

ll comb[64+5][64+5];

ll calc_comb(ll a, ll b){
    if(comb[a][b]!=0) return comb[a][b];
    
    if(b>a) return 0;
    if(b==0) return 1;
    if(b==1) return a;

    return comb[a][b] = calc_comb(a-1, b-1) + calc_comb(a-1, b);
}

ll calc(ll n, ll ini){
    ll sum=0;
    for(ll i=1; i<=n; i++){
        sum += calc_comb(n, i) * (i+ini);
    }
    return sum;
}

int main(){
    fast_io;

    ll n;
    cin >> n;

    ll resp = 0, qnt=0;
    
    for(ll i=0; i<64; i++){
        qnt += ((n&(1LL<<i)) != 0);
    }

    for(ll i=0; i<64; i++){
        if((n&(1LL<<i)) != 0){
            resp += qnt + calc(i, qnt-1);
            qnt--;
        }
    }

    cout << resp << endl;
    
    return 0;
}
