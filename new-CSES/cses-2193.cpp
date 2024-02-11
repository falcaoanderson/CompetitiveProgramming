// 31/01/24 //
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
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n;
    cin >> n;

    ll area = 0LL, b=0;

    vector<ll> x(n), y(n);
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];

    for(int i=1; i<=n; i++){
        area += y[i%n] * x[i-1] - x[i%n]*y[i-1];

        b += __gcd(abs(x[i%n]- x[i-1]), abs(y[i%n] - y[i-1])); 
    }
    
    cout << (abs(area)-b+2LL)/2LL << " " << b << endl;

    return 0;
}
