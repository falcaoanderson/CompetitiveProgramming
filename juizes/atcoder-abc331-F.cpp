// 30/01/24 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e6) + 5;
const ll M1  = (1e9) + 7;
const ll M2  = (1e9) + 9;
const ll p = 31;

ll exp(ll a, ll b, ll m){ // 0^0 = 1
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

int n;
ll bit[MAXN][5];
/*
0 - prefix M1
1 - sufix M1
2 - prefix M2
3 - sufix M2
*/

ll query(int i, int id, ll MOD){
    ll sum=0;

    while(i>0){
        sum = (sum + bit[i][id])%MOD;
        i -= (i&-i); 
    }

    return sum;
}
void update(int i, int id, ll delta, ll MOD){
    while(i<=n){
        bit[i][id] = (bit[i][id] + delta + MOD)%MOD;
        i += (i&-i);
    }
}

ll inv_p[] = {exp(p, M1-2, M1), exp(p, M2-2, M2), 0, 0, 0};

ll f_hash(int i, int j, int id, ll mod){
    return ( (query(j, id, mod) - query(i-1, id, mod) + mod) * exp(inv_p[id/2], i-1, mod) ) % mod;
}

int main(){
    fast_io;

    int q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<ll> p1(n), p2(n);
    p1[0] = p2[0] = 1;
    for(int i=1; i<n; i++){
        p1[i] = (p1[i-1] * p)%M1;
        p2[i] = (p2[i-1] * p)%M2;
    }

    ll h0=0, h1=0, h2=0, h3=0;

    for(int i = 0; i<n; i++){
        ll  c = (ll) (s[i]     - 'a') + 1;
        ll bc = (ll) (s[n-1-i] - 'a') + 1;
        
        //prefix
        h0 = (c * p1[i]) % M1;
        h2 = (c * p2[i]) % M2;
        update(i+1, 0, h0, M1);
        update(i+1, 2, h2, M2);

        //sufix
        h1 = (bc * p1[i]) % M1;
        h3 = (bc * p2[i]) % M2;
        update(i+1, 1, h1, M1);
        update(i+1, 3, h3, M2);
    }   

    while(q--){
        int op;
        cin >> op;

        if(op==1){ //update;
            int i; char c;
            cin >> i >> c;
            i--;

            ll a, b, delta;

            //prefix1
            a = (ll) (s[i] - 'a') + 1;
            a = (a * p1[i]) % M1;

            b = (ll) (c - 'a') + 1;
            b = (b * p1[i]) % M1; 

            delta = (b - a + M1)%M1;
            update(i+1, 0, delta, M1);

            //sufix1
            a = (ll) (s[i] - 'a') + 1;
            a = (a * p1[n-1-i]) % M1;

            b = (ll) (c - 'a') + 1;
            b = (b * p1[n-1-i]) % M1; 

            delta = (b - a + M1)%M1;
            update(n-i, 1, delta, M1);

            //prefix2
            a = (ll) (s[i] - 'a') + 1;
            a = (a * p2[i]) % M2;

            b = (ll) (c - 'a') + 1;
            b = (b * p2[i]) % M2; 

            delta = (b - a + M2)%M2;
            update(i+1, 2, delta, M2);

            //sufix2
            a = (ll) (s[i] - 'a') + 1;
            a = (a * p2[n-1-i]) % M2;

            b = (ll) (c - 'a') + 1;
            b = (b * p2[n-1-i]) % M2; 

            delta = (b - a + M2)%M2;
            update(n-i, 3, delta, M2);


            s[i] = c;
        }
        else{ //query
            int a, b;
            cin >> a >> b;

            cout << (((f_hash(a, b, 0, M1) == f_hash(n+1-b, n+1-a, 1, M1) && f_hash(a, b, 2, M2) == f_hash(n+1-b, n+1-a, 3, M2))) ?"Yes":"No") << endl;
        }
    }

    return 0;
}
