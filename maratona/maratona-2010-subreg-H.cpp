// 02/03/24 //
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
const int MAXN = (1e5) + 5;
const int MAXM = (1e4) + 5;
const ll MOD[]  = {(int)(1e9) + 7, (int)(1e9) + 9, 0, 0};
const ll p = 31;

ll pot_p[MAXN][5];

int num_nota(string s){
    if(s=="C" || s=="B#") return 1;
    if(s=="C#" || s=="Db") return 2;
    if(s=="D") return 3;
    if(s=="Eb" || s=="D#") return 4;
    if(s=="E" || s=="Fb") return 5;
    if(s=="F" || s=="E#") return 6;
    if(s=="Gb" || s=="F#") return 7;
    if(s=="G") return 8;
    if(s=="Ab" || s=="G#") return 9;
    if(s=="A") return 10;
    if(s=="Bb" || s=="A#") return 11;
    if(s=="B" || s=="Cb") return 12;

    return 0;
}

void compute_hash(vector<ll> &v, vector<ll> &h, int op_mod){
    h[0] = v[0];
    for(int i=1; i<sz(v); i++){
        h[i] = ((h[i-1] * p)%MOD[op_mod] + v[i])%MOD[op_mod];
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

int main(){
    fast_io;

    init_pot_p(1e5);

    while(true){
        int n, m;
        cin >> n >> m;

        if(n==0) break;

        vector<ll> music(n), trecho(m);

        for(int i=0; i<n; i++){
            string s;
            cin >> s;

            music[i] = num_nota(s);
            // cout << music[i] << " ";
        }
        // cout << endl;

        for(int i=0; i<m; i++){
            string s;
            cin >> s;

            trecho[i] = num_nota(s);
            // cout << trecho[i] << " ";
        }
        // cout << endl;

        vector<ll> hash_music0(n), hash_music1(n);
        vector<ll> hash_trecho0(m), hash_trecho1(m);

        compute_hash(music, hash_music0, 0);
        compute_hash(music, hash_music1, 1);

        bool resp = 0;

        for(int k=0; k<12 && !resp; k++){
            for(ll &i: trecho){
                i = (i+1)%12LL;
                if(i==0) i = 12;
            }

            compute_hash(trecho, hash_trecho0, 0);
            compute_hash(trecho, hash_trecho1, 1);
            
            ll h0 = hash_trecho0.back();
            ll h1 = hash_trecho1.back();

            for(int i=0; i<=n-m && !resp; i++){
                ll mhash0 = sub_hash(hash_music0, i, i+m-1, 0);
                ll mhash1 = sub_hash(hash_music1, i, i+m-1, 1);

                if(mhash0==h0 && mhash1==h1){
                    resp = 1;
                }
            }
        }

        cout << (resp?"S":"N") << endl;
    }

    return 0;
}