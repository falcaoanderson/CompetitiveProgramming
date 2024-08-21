/*
21/08/24 
Problem: Prime Multiples - CSES
Complexity: O(k*2^k)
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    ll n;
    int k;
    cin >> n >> k;

    vector<ll> p(k);
    for(int i=0; i<k; i++) cin >> p[i];
    
    ll resp = 0;

    for(int mask=1; mask<(1<<k); mask++){
        int qnt=0;
        ll value=1LL;

        for(int i=0; i<k; i++){
            if((mask&(1<<i))!=0){
                qnt++;

                if(value >= (n/p[i]) + 1){
                    value = n+1;
                    break;
                }

                value *= p[i];
            }
        }

        resp += (ll)(2*(qnt&1)-1) * (n/value);    
    }

    cout << resp << endl;

    return 0;
}
