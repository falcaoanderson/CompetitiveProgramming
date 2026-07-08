/*
26/02/26 

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

    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        int l;
        cin >> l;

        vector<int> vaux(l);
        set<int> mset;

        for(int j=0; j<l; j++){
            cin >> vaux[j];
        }
        for(int j=l-1; j>=0; j--){
            if(mset.find(vaux[j])!=mset.end()){
                vaux[j] = -vaux[j];
            }
            else{
                mset.insert(vaux[j]);
            }
        }
        for(int j=0; j<l; j++){
            if(vaux[j]>0) v[i].PB(vaux[j]);
        }
    }
    
    vector<bool> flag(1e6 + 1);

    auto cmp = [&flag](vector<int>& a, vector<int> &b) -> bool {
        int ia = (int)a.size() - 1, ib = (int)b.size() - 1;

        while(ia>=0 && ib>=0){
            while(ia >= 0 && flag[a[ia]]) ia--;
            while(ib >= 0 && flag[b[ib]]) ib--;
            if(ia < 0 && ib >= 0) return true;
            if(ib < 0) return false;
            

            if(a[ia] < b[ib]) return true;
            if(a[ia] > b[ib]) return false;
            
            ia--; ib--;
        }

        if(ia < 0 && ib >= 0) return true;
        return false;
    }; 
    

    vector<int> ans;
    vector<bool> choosed(n);
    for(int k=0; k<n; k++){
        int idx_min = -1;

        for(int i=0; i<n; i++){
            if( !choosed[i] && (idx_min==-1 || cmp(v[i], v[idx_min])) ){
                idx_min = i;
            }
        }

        choosed[idx_min] = 1;
        for(int i = (int)v[idx_min].size() - 1; i>=0; i--){
            int x = v[idx_min][i];
            if(!flag[x]){
                ans.PB(x);
                flag[x] = 1;
            }
        }
    }

    for(int x: ans) cout << x << " ";
    cout << endl;
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
