/*
11/02/26 

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

typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;

        bool flag = 0;
        for(ll y=x+1; y<=x+90 && !flag; y++){
            ll aux = y, sum=0;
            while(aux>0){
                sum += (aux%10LL);
                aux /= 10LL;
            }
            if(y - sum == x) flag = 1;
        }

        cout << (flag? 10: 0) << endl;
    }

    return 0;
}
