/*
17/07/25 

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

int main(){
    fast_io;

    int n;
    string s;
    cin >> n >> s;

    int cnt=0;
    for(int i=0; i<n; i++){
        cnt += (s[i]=='0');
    }

    if(n%2==0 && cnt*2==n){
        cout << 2 << endl;
        cout << s[0] << endl;
        for(int i=1; i<n; i++)
            cout << s[i];
        cout << endl;
    }
    else{
        cout << 1 << endl;
        cout << s << endl;
    }

    return 0;
}
