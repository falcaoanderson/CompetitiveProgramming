// 28/10/20 // 3:50 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<ll, ll> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    cin >> n;
    
    vector<pii> v(n);
    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    ll resp = 0, prefix=0;
    for(int i=0; i<n; i++){
        prefix += v[i].first;
        
        resp += v[i].second - prefix;
    }

    cout << resp << endl;

    return 0;
}
