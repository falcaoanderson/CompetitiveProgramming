/*
25/09/25 

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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> va, vb;
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                va.PB(i-SZ(va));
            }
            else{
                vb.PB(i-SZ(vb));
            }
        }

        ll ca=0, cb=0;
        int na = SZ(va), nb=SZ(vb);

        if(na<=1 || nb<=1){
            cout << 0 << endl;
            continue;
        }

        for(int i=0; i<na; i++){
            ca += (ll)abs(va[i]-va[(na-1)/2]);
        }
        for(int i=0; i<nb; i++){
            cb += (ll)abs(vb[i]-vb[(nb-1)/2]);
        }

        cout << min(ca, cb) << endl;
    }

    return 0;
}
