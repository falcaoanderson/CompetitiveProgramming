/*
08/08/25 

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

    ll n, b;
    cin >> n >> b;

    ll pot, qnt, resp = LINF;

    qnt = 0;
    while (b % 2LL == 0) {
        b /= 2LL;
        qnt++;
    }
    if(qnt>0){
        pot = 2LL;
        ll crr=0;

        while(n/pot > 0){
            crr += n/pot;
            if(n/pot<2LL) break;
            pot *= 2LL;
        }
        resp = min(resp, crr/qnt);
    }

    for (ll d = 3; d * d <= b; d += 2) {
        qnt = 0;
        while(b % d == 0) {
            b /= d;
            qnt++;
        }

        if(qnt>0){
            pot = d;
            ll crr=0;

            while(n/pot > 0){
                crr += n/pot;

                if(n/pot<d) break;

                pot *= d;
            }
            resp = min(resp, crr/qnt);
        }
    }
    if (b > 1){
        pot = b;
        ll crr=0;

        while(n/pot > 0){
            crr += n/pot;
            if(n/pot<b) break;
            pot *= b;
        }

        resp = min(resp, crr);
    }

    cout << resp << endl;

    return 0;
}
