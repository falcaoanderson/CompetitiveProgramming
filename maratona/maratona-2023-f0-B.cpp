// 17/06/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){
    if(b==0) return 1LL;

    if(b&1) return (a*exp(a, b-1, m))%m;
    return exp((a*a)%m, b/2, m)%m;
}

int main(){
    fast_io;

    double a, b, c;

    cin >> a >> b >> c;

    char op;
    cin >> op;

    if(op=='A'){
        cout << (ll)(a + 3.0*b/2.0 + 5.0*c/2.0) << endl;
    }
    else if(op=='B'){
        cout << (ll)(b + 2.0*a/3.0 + 5.0*c/3.0) << endl;
    }
    else{
        cout << (ll)(c + 2.0*a/5.0 + 3.0*b/5.0) << endl;
    }

    return 0;
}