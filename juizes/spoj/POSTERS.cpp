/*
09/02/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

void solve(){
    int n;
    cin >> n;

    vector< pair<int, pii> > v;
    set<int> crr, resp;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        v.PB({a-1, {0, -i}});
        v.PB({b, {1, i}});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < 2 * n; i++){
        int t = v[i].SS.SS, op = v[i].SS.FF;

        if(op==0){
            t = -t;
            crr.insert(t);
        }
        else{
            crr.erase(t);
        }

        if(!crr.empty()){
            resp.insert(*crr.rbegin());
        }
    }

    cout << resp.size() << endl;
    // for(int x: resp) cout << x << " ";
    // cout << endl;
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
