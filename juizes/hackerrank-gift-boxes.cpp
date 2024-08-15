/*
14 and 15 /08/24 
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

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e6) + 5;

const ll MOD[]  = {(int)(1e9) + 7, (int)(1e9) + 9, 0, 0};
const ll p = 53;

ll potp[MAXN][5];

void init_potp(){
    potp[0][0] = potp[0][1] = 1LL;

    for(int i=1; i<MAXN-5; i++){
        potp[i][0] = (potp[i-1][0] * p)%MOD[0]; 
        potp[i][1] = (potp[i-1][1] * p)%MOD[1];
    }
}

inline int get_num(char c){
    return ('a'<=c ? c-'a'+1: c-'A'+27);
}

void solve(){
    string sa, sb;
    cin >> sa >> sb;

    int na=sz(sa), nb=sz(sb);
    vector<ll> ha(2);

    for(int i=0; i<na; i++){
        ha[0]  = (ha[0] + get_num(sa[i]) * potp[i][0])%MOD[0];
        ha[1]  = (ha[1] + get_num(sa[i]) * potp[i][1])%MOD[1];
    }

    vector<ll> hb[5];
    hb[0].resize(nb+1);
    hb[1].resize(nb+1);

    int top=0, resp=0;
    for(char c: sb){
        hb[0][top+1] = (hb[0][top] + get_num(c) * potp[top][0])%MOD[0];
        hb[1][top+1] = (hb[1][top] + get_num(c) * potp[top][1])%MOD[1];
        top++;

        if(top>=na && 
        (hb[0][top]-hb[0][top-na]+MOD[0])%MOD[0] == (ha[0]*potp[top-na][0])%MOD[0] &&
        (hb[1][top]-hb[1][top-na]+MOD[1])%MOD[1] == (ha[1]*potp[top-na][1])%MOD[1]){
            resp++;
            top -= na;
        }
    }

    cout << resp << endl;
}

int main(){
    fast_io;

    init_potp();

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}