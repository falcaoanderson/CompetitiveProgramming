/*
24/04/26 

Using the idea from the editorial
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

int n;
int query(int qnt, vector<int>& idx){
    if(qnt==1) return 1;
    if(qnt==n) return 0;

    cout << "? " << qnt << " ";
    for(int i=1; i<=qnt; i++){
        cout << idx[i] << " ";
    }
    cout << endl;
    
    int q;
    cin >> q;

    if(q==-1) exit(-1);

    return q;
}

int bsearch(vector<int>& idx){
    int l=1, r=n, mid, val;
    while(l<=r){
        mid = (l + r) / 2;

        int q = query(mid, idx);

        if((mid - q) & 1){
            val = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return val;
}

void solve(){
    cin >> n;
    n = 2*n + 1;
    
    vector<int> pos, idx(n+1);
    for(int i=1; i<=n; i++) idx[i] = i;

    int i = bsearch(idx);
    pos.PB(idx[i]);
    swap(idx[1], idx[i]);

    i = bsearch(idx);
    pos.PB(idx[i]);
    swap(idx[2], idx[i]);

    i = bsearch(idx);
    pos.PB(idx[i]);

    cout << "! ";
    for(int x: pos) cout << x << " ";
    cout << endl;
}

int main(){
    // fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
