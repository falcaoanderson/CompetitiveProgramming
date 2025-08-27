/*
23/08/25 

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

    int n, d;
    cin >> n >> d;
    
    vector<int> v;
    int val=0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;

        if(x>0){
            v.PB(i+1);
            val = x;
        };
    }

    if(SZ(v)==1 && val>=d){
        for(int i=0; i<d; i++) cout << v[0] << " ";
        cout << endl;
    }
    else if(SZ(v)>=2){
        for(int i=0; i<d; i++) cout << v[i&1] << " ";
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}
