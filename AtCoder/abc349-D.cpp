/*
12/08/25 

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

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

int main(){
    fast_io;

    ll l, r;
    cin >> l >> r;

    vector< pair<ll, ll> > resp;
    
    while(l<r){
        ll pot=0, aux=l;
        while(aux%2LL==0 && l+(1LL<<(pot+1LL))<=r){
            aux/=2LL;
            pot++;
        }

        resp.EB(l, l+(1LL<<pot));
        l += (1LL<<pot);
    }

    cout << resp.size() << endl;
    for(auto p: resp){
        cout << p.FF << " " << p.SS << endl;
    }

    return 0;
}
