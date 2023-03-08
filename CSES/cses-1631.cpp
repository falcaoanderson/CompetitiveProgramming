// 28/10/20 // 4:20 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    cin >> n;
    
    vector<ll> v(n);
    ll sum=0;

    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }
    
    sort(v.begin(), v.end());

    cout << max(sum, 2*v[n-1]) << endl;
    
    return 0;
}
