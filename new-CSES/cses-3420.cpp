/*
26/08/25 

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

int main(){
    fast_io;
    
    ll n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    set<int> window;
    ll l=0, resp = 0;
    for(ll r=0; r<n; r++){
        if(window.find(v[r])==window.end()){
            window.insert(v[r]);
        }
        else{    
            resp += ((r-l)*(r-l+1LL)) / 2LL;
            
            while(v[l]!=v[r]){
                window.erase(v[l]);
                l++;
            }
            l++;
            
            resp -= ((r-l)*(r-l+1LL)) / 2LL;
        }
    }
    resp += ((n-l)*(n-l+1LL)) / 2LL;

    cout << resp << endl;

    return 0;
}
