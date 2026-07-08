/*
21/02/26 

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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ones=0, zeros=0;
    for(char c: s){
        ones += (int)(c=='1');
        zeros += (int)(c=='0');
    }

    if(zeros == n){
        cout << 0 << endl;
    }
    else if((ones % 2) == 0){
        cout << ones << endl;
        for(int i=0; i<n; i++){
            if(s[i]=='1') cout << i+1 << " ";
        }        
        cout << endl;
    }
    else if((zeros % 2) == 1){
        cout << zeros << endl;
        for(int i=0; i<n; i++){
            if(s[i]=='0') cout << i+1 << " ";
        }        
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
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
