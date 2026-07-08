/*
08/03/26 

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
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int it_a = 0;
    multiset<int> dset;
    for(int i = 0; i < min(n+1, m); i++) dset.insert(0);

    for(int t = 1; t <= a[n-1]; t++){
        while(n - it_a + 1 < SZ(dset)){
            dset.erase(dset.begin());
        }

        int x = *dset.begin();
        dset.erase(dset.find(x));
        dset.insert(x+1);    
        
        if(it_a < n && t == a[it_a]){
            x = *dset.rbegin();
            dset.erase(dset.find(x));
            dset.insert(0);

            it_a++;
        }
    }

    cout << *dset.rbegin() + l - a[n-1] << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
