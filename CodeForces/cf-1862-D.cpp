// 07/09/23 //
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

void solve(){
    ll n;
    cin >> n;

    ll left = 2, right=1414213562LL, mid;
    ll resp = 2;

    while(left<=right){
        mid = (left+right)/2LL;

        ll aux = (mid*(mid-1LL))/2LL;

        if(aux<=n){
            resp = max(resp, mid);
            left = mid+1LL;
        }
        else{
            right = mid-1LL;
        }
    }
    resp += (n - ((resp*(resp-1LL))/2LL));

    cout << resp << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
