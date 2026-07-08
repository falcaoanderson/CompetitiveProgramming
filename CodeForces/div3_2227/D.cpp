/*
30/04/26 

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

int calc(int l, int r, vector<int> &v){
    int n = SZ(v) / 2;
    set<int> mex;
    for(int i=0; i<=n; i++) mex.insert(i);

    int ans = 1, x = l, y = r;
    while(x<=y){
        if(v[x] == v[y]){
            mex.erase(v[x]);
            ans = *mex.begin();
        }
        else{
            return 1;
        }
        
        x++;
        y--;
    }

    x = l - 1;
    y = r + 1;
    while(0 <= x && y < 2*n){
        if(v[x] == v[y]){
            mex.erase(v[x]);
            ans = *mex.begin();
        }
        else{
            return ans;
        }
        
        x--;
        y++;
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(2*n);
    int pos1=-1, pos2=-1;
    for(int i=0; i<2*n; i++){
        cin >> v[i];

        if(v[i]==0){
            if(pos1==-1) pos1 = i;
            else pos2 = i; 
        }
    }

    cout << max(calc(pos1, pos1, v), max(calc(pos2, pos2, v), calc(pos1, pos2, v))) << endl;
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
