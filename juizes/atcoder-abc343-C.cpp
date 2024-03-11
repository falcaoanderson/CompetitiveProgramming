/*
09/03/24 
Problem: Atcoder ABC 343 - C
Complexity: O(n^(1/3))
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

int main(){
    fast_io;

    ll n;
    cin >> n;

    ll resp = 0;

    for(ll x=0; (x*x*x)<=n; x++){
        ll k = x*x*x;

        string s = to_string(k);

        bool flag=1;
        int s_sz = sz(s);
        for(int i=0; i<s_sz; i++){
            if(s[i]!=s[s_sz-i-1]) flag = 0;
        }

        if(flag) resp = k;
    }

    cout << resp << endl;

    return 0;
}
