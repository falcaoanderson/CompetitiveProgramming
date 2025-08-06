/*
06/08/25 

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

int calc(int x){
    int resp = 1;

    while(x>0){
        resp *= (x%10);
        x /= 10;
    }
    return resp;
}

int main(){
    fast_io;

    int n;
    cin >> n;

    if(n<10){
        cout << n << endl;
        return 0;
    }

    int resp = calc(n);
    int noves = 9;
    for(int i=10; i<=n; i*=10){
        while(n%i != noves){
            n-=(i/10);
        }
        resp = max(resp, calc(n));
        
        if(noves == 999999999) break;
        noves += 9*i;
    }

    cout << resp << endl;

    return 0;
}
