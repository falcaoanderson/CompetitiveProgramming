/*
01/11/25 

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
    int n, k, x;
    cin >> n >> k >> x;

    set<pii> pos;
    set<int> resp;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    pos.insert({v[0]-0, 0});
    for(int i=0; i<n; i++){
        pos.insert({0, v[i]});

        if(i>0 && v[i]-v[i-1]>1){
            int med = (v[i]+v[i-1])/2;
            pos.insert({med-v[i-1], med});
            
            if(((v[i]+v[i-1])&1) && (v[i]-v[i-1])>2){
                pos.insert({med-v[i-1], med+1});
            }
        }
    }
    pos.insert({x-v[n-1], x});
    
    for(int i=0; i<k; i++){
        int d=-1, coord=-1;
        while(!pos.empty()){
            auto it = pos.rbegin();
            d = (*it).FF;
            coord = (*it).SS;
            pos.erase({d, coord});

            if(resp.find(coord)==resp.end()) break;
        }

        resp.insert(coord);

        if(coord < x && resp.find(coord+1) == resp.end()){
            pos.insert({max(0, d-1), coord+1});
        }
        if(0 < coord && resp.find(coord-1) == resp.end()){
            pos.insert({max(0, d-1), coord-1});
        }
    }

    for(auto coord: resp){
        cout << coord << " ";
    }
    cout << endl;
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
