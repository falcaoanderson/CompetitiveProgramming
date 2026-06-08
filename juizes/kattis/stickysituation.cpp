/*
23/01/26

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

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<ll> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    bool resp = 0;

    for(int i=2; i<n && !resp; i++){
        resp = (v[i-2] + v[i-1] > v[i]);
    }

    cout << (resp? "possible": "impossible") << endl;

    return 0;
}