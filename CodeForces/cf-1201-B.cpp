/*
04/01/25 
CF 577 Div.2 A
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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;
    
    int n;
    ll sum=0, maxv=0;
    cin >> n;

    for(int i=0; i<n; i++){
        ll x;
        cin >> x;

        sum += x;
        maxv = max(maxv, x);
    }

    if(sum & 1LL || 2LL*maxv>sum){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }

    return 0;
}
