// 09/04/23 //
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> prefix(n+1);

    for(int i=1; i<=n; i++){
        cin >> prefix[i];

        prefix[i] += prefix[i-1];
    }
    
    ll max_sum = -2e14-1;
    multiset<ll> mset;

    for(int i=a; i<=n; i++){
        mset.insert(prefix[i-a]);
        if(i>b) mset.erase(mset.find(prefix[i-b-1]));
        
        auto it = mset.begin();

        max_sum = max(max_sum, prefix[i] - (*it));
    }

    cout << max_sum << endl;

    return 0;
}