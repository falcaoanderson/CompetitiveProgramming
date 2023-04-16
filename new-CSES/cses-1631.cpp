// 15/04/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
inline ll max(ll a, ll b){
    return (a>b? a: b);
}
inline ll min(ll a, ll b){
    return (a<b? a: b);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    ll sum = 0LL, max_val = -1LL;
    for(int i=0; i<n; i++){
        ll val;
        cin >> val;

        sum += val;
        max_val = max(max_val, val);
    }

    cout << max(sum, 2*max_val) << endl;

    return 0;
}