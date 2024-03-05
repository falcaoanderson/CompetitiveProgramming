/*
05/03/24 
Problem: Kattis - dvaput
Complexity: o(n*log^2(n))
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
const ll MOD[]  = {(int)(1e9) + 7, (int)(1e9) + 9, 0, 0};
const ll p = 31;

ll pot_p[MAXN][5];
void compute_hash(string &s, vector<ll> &h, int op_mod){
    h[0] = (ll)(s[0]-'a'+1);

    for(int i=1; i<sz(s); i++){
        h[i] = ((h[i-1] * p)%MOD[op_mod] + (ll)(s[i]-'a'+1))%MOD[op_mod];
    }
}

ll sub_hash(vector<ll> &h, int i, int j, int op_mod){
    if(i==0) return h[j];

    return (h[j] - (h[i-1] * pot_p[j-i+1][op_mod])%MOD[op_mod] + MOD[op_mod])%MOD[op_mod];
}

void init_pot_p(int n){
    pot_p[0][0] = pot_p[0][1] = 1;
    for(int i=1; i<=n; i++){
        pot_p[i][0] = (pot_p[i-1][0] * p)%MOD[0];
        pot_p[i][1] = (pot_p[i-1][1] * p)%MOD[1];
    }
}
pii subs[MAXN];

int main(){
    fast_io;

    int n;
    string s;
    cin >> n >> s;

    init_pot_p(n);

    vector<ll> h0(n), h1(n);
    compute_hash(s, h0, 0);
    compute_hash(s, h1, 1);

    int l=1, r=n-1, resp=0;

    while(l<=r){
        int mid = (l+r)/2;
    
        for(int i=0; i<n-mid+1; i++){
            subs[i] = {sub_hash(h0, i, i+mid-1, 0), sub_hash(h1, i, i+mid-1, 1)};
        }
        sort(subs, subs+(n-mid+1));
        
        bool sol = 0;
        for(int i=0; i<n-mid && !sol; i++) sol = (subs[i]==subs[i+1]);

        if(sol){
            resp = mid;
            l = mid+1;
        }
        else{
            r=mid-1;
        }
    }

    cout << resp << endl;

    return 0;
}
