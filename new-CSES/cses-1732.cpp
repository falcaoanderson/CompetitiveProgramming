/*
11/02/24 
Problem: CSES - Finding Borders
Complexity: O(n)
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

const ll MOD1 = (1e9) + 7;
const ll MOD2 = (1e9) + 9;
const ll p = 31;

int main(){
    fast_io;

    string s;
    cin >> s;

    ll p1=1, p2=1;
    ll prefix1=0, sufix1=0;
    ll prefix2=0, sufix2=0;

    int n = sz(s);

    for(int i=0; i<n-1; i++){
        ll c  = s[i]     -'a' + 1;
        ll ci = s[n-i-1] -'a' + 1;

        prefix1 = (prefix1 + c * p1)%MOD1;
        prefix2 = (prefix2 + c * p2)%MOD2;

        sufix1 = (ci + sufix1*p)%MOD1;
        sufix2 = (ci + sufix2*p)%MOD2;

        p1 = (p1 * p)%MOD1;
        p2 = (p2 * p)%MOD2;

        if(prefix1==sufix1 && prefix2==sufix2){
            cout << i+1 << " ";
        }
    }
    cout << endl;

    return 0;
}
