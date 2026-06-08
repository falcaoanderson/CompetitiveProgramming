/*
31/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll gcd(ll a, ll b){
    if(b==0) return a;
    if(a==0) return b;
    return gcd(b, a%b);
}

int main(){
    fast_io;

    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll aux = gcd(x, y);
    x /= aux;
    y /= aux;
    cout << min(a / x, b / y) << endl;

    return 0;
}