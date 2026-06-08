/*
24/01/26

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

void solve(){
    int n;
    cin >> n;

    priority_queue<pii> pq;
    pq.push({n, -1});

    vector<int> v(n+1);

    for(int i=1; i<=n; i++){
        pii crr = pq.top();
        pq.pop();

        int l = -crr.SS, r = crr.FF + (-crr.SS) - 1;
        int mid = (l+r)/2;
        // cout << l << " " << r << " " << mid << endl;
        v[mid] = i;
        
        if(l<mid){
            pq.push({mid-l, -l});
        }
        if(mid<r){
            pq.push({r-mid, -(mid+1)});
        }
    }
    
    for(int i=1; i<=n; i++) cout << v[i] << " ";
    cout << endl;
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