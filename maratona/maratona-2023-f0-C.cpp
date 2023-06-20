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

int main(){
    fast_io;

    ll n, k;
    cin >> n >> k;

    ll mod = 2LL*n+1LL;

    for(ll i=2LL*n; i>=1LL; i--){
        if(i*i==k) continue;

        if((i*i)%(mod)==k%mod){
            cout << (i*i) << endl;
            break;
        }
    }

    return 0;
}
