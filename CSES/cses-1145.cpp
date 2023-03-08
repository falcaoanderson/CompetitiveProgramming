// 03/11/20 // xx:xx PM //

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
    
    vector<int> v;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        auto it = lower_bound(v.begin(), v.end(), val);

        if(it==v.end()) v.pb(val);
        else *it = val;
    }

    cout << (int)v.size() << endl;

    return 0;
}
