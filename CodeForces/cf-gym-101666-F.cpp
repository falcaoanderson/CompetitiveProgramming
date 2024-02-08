// 27/01/24 //
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

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int a=0, b=0;
    for(int i=n-1; i>=0; i--){
        if( (i%2) == ((n-1)%2)) a += v[i];
        else b+= v[i];
    }

    cout << a << " " << b << endl;

    return 0;
}
