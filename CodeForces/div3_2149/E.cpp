/*
25/09/25 

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
    int n, k, minsz, maxsz;
    cin >> n >> k >> minsz >> maxsz;

    vector<pii> auxv(n);
    for(int i=0; i<n; i++){
        cin >> auxv[i].FF;
        auxv[i].SS = i;  
    }
    sort(auxv.begin(), auxv.end());
    
    vector<int> v(n);
    int maxval=0;
    for(int i=0; i<n; i++){
        if(i>0 && auxv[i].FF!=auxv[i-1].FF) maxval++;
        v[auxv[i].SS] = maxval;
    }

    // cout << "v: ";
    // for(int x: v) cout << x << " ";
    // cout << endl;

    vector<int> last(maxval+1, -1);
    int r=-1, z=-1, count=0;
    ll resp = 0;

    for(int l=0; l+minsz<=n; l++){
        while(r-l+2<=maxsz && r<n-1 && count<k){ //primeira posicao valida
            r++;
            
            if(last[v[r]]==-1) count++;
            last[v[r]] = r;
        }

        z = max(z, r);
        while(z-l+2<=maxsz && z<n-1 && count==k && last[v[z+1]]!=-1){ // ultima posicao valida
            z++;
        }
 
        // cout << l << " " << r << " " << z << " " << count <<endl;
        
        if(count==k && l+minsz-1<=z){
            resp += (ll) z - max(r, l+minsz-1) + 1;
        }

        if(last[v[l]]==l){
            last[v[l]] = -1;
            count--;
        }
    }

    cout << resp << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
        // cout << endl << endl;
    }

    return 0;
}
