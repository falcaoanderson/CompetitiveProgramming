/*
18/05/26 

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

void solve(){
    string s;
    cin >> s;

    string temp_s = "";
    int ans = 0;
    for(char c: s){
        if(c == '4'){
            ans++;
        }
        else{
            temp_s += c;
        }
    }
    swap(s, temp_s);

    vector<int> q2(SZ(s)+1);
    for(int i=SZ(s)-1; i>=0; i--){
        q2[i] = q2[i+1] + (int)(s[i] == '2');
    }
    int aux_ans = q2[0], q13 = 0;

    for(int i=0; i<SZ(s); i++){
        if(s[i] == '1' || s[i] == '3') q13++;

        aux_ans = min(aux_ans, q13 + q2[i+1]);
    }

    cout << ans + aux_ans << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
