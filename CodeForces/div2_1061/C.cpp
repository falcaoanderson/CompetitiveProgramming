/*
24/10/25 

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
const int MAXVAL = (1e6) + 5;
const int MOD  = (1e9) + 7;

ll qnt[MAXVAL];
int isqrt[MAXVAL];

int main(){
    fast_io;

    int n;
    cin >> n;

    qnt[0] = 1;

    for(int i=1; i<=1e6; i++){
        isqrt[i] = isqrt[i-1];
        if((isqrt[i]+1)*(isqrt[i]+1)==i){
            isqrt[i]++;
        }
    }

    for(int i=1; i<=n; i++){
        int val;
        cin >> val;
        
        for(int d=1; d*d<val; d++){
            if(val % d == 0){
                qnt[val/d] = (qnt[val/d] + qnt[val/d - 1]) % MOD;
            }
        }
        for(int d=isqrt[val]; d>=1; d--){
            if(val % d == 0){
                qnt[d] = (qnt[d] + qnt[d-1]) % MOD;
            }
        }
    }

    ll resp = 0;
    for(int i=1; i<=n; i++) resp = (resp + qnt[i]) % MOD;
    
    cout << resp << endl;

    return 0;
}
