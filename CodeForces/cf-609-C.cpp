// 29/01/23 //
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

    ll n;
    cin >> n;

    vector<ll> v(n);
    ll sum = 0;

    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    ll resp = 0;

    for(int i=0; i<n; i++){
        if(n-i <= sum%n){
            resp += abs(v[i] - (sum/n + 1LL) );
        }
        else{
            resp += abs(v[i] - sum/n);
        }
    }

    cout << resp/2LL << endl;

    return 0;
}
