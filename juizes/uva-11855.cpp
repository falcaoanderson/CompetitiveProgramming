/*
25 and 26 /03/24 
Problem: 
Complexity:
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

typedef pair<ll, ll> pll;

const int MAXN = (1e3) + 5;
const ll MOD[]  = {(ll)(1e9) + 7, (ll)(1e9) + 9, 0, 0};
const ll p = 31LL;

int n;
string s;
ll pot_p[MAXN][5];
ll h[MAXN][5];

void compute_hash(int op_mod){
    h[0][op_mod] = (ll)(s[0]-'A'+1);

    for(int i=1; i<n; i++){
        h[i][op_mod] = ((h[i-1][op_mod] * p)%MOD[op_mod] + (ll)(s[i]-'A'+1))%MOD[op_mod];
    }
}

ll sub_hash(int i, int j, int op_mod){
    if(i==0) return h[j][op_mod];

    return (h[j][op_mod] - (h[i-1][op_mod] * pot_p[j-i+1][op_mod])%MOD[op_mod] + MOD[op_mod])%MOD[op_mod];
}

void init_pot_p(int n){
    pot_p[0][0] = pot_p[0][1] = 1;
    for(int i=1; i<=n; i++){
        pot_p[i][0] = (pot_p[i-1][0] * p)%MOD[0];
        pot_p[i][1] = (pot_p[i-1][1] * p)%MOD[1];
    }
}

void solve(){
    n = sz(s);
    compute_hash(0);
    compute_hash(1);

    queue<int> idx;
    for(int i=0; i<n; i++) idx.push(i);

    map<pair<ll, ll>, int> freq_hash;
    bool flag = 0;
    for(int l=1; l<n && !idx.empty(); l++){
        freq_hash.clear();
        
        int sz_idx = sz(idx);
        for(int k=0; k<sz_idx; k++){
            int i = idx.front(); idx.pop();

            if(i+l-1<n){
                pll ph = {sub_hash(i, i+l-1, 0), sub_hash(i, i+l-1, 1)};

                if(freq_hash.find(ph)==freq_hash.end()) freq_hash[ph] = 1;    
                else                                    freq_hash[ph]++; 

                idx.push(i);
            }
        }

        int max_freq = 1;
        sz_idx = sz(idx);
        for(int k=0; k<sz_idx; k++){
            int i = idx.front(); idx.pop();
        
            pll ph = {sub_hash(i, i+l-1, 0), sub_hash(i, i+l-1, 1)};

            max_freq = max(max_freq, freq_hash[ph]); 

            if(freq_hash[ph]>1) idx.push(i);
        }

        if(max_freq==1) break;
        
        flag = 1;
        cout << max_freq << endl;
    }   

    if(flag) cout << endl;
}

int main(){
    fast_io;

    init_pot_p(1e3);

    string aux;
    while(getline(cin, aux)){
        s = "";
        for(char c: aux) if(c!=' ') s += c;

        solve();
    }
    return 0;
}
