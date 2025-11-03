/*
24/10/25 

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
const ll MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n;
    ll fix, var;

    cin >> n >> fix >> var;

    vector<pii> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].FF >> v[i].SS;
    }

    sort(v.begin(), v.end());

    ll resp = 0;
    int num_tvs = 0;
    multiset<pii> tvs;
    vector<pii> last_show; 

    for(int i=0; i<n; i++){
        auto it = tvs.lower_bound({v[i].FF, 0});
         
        if(tvs.empty() || it == tvs.begin()){
            tvs.insert({v[i].SS, num_tvs});
            last_show.PB(v[i]);
            num_tvs++;

            resp += fix + var * (ll)(v[i].SS-v[i].FF);
            resp %= MOD;
        }
        else{
            it--;
            int id = it->second;
            tvs.erase(it);

            if((v[i].FF - last_show[id].SS) * var <= fix){
                resp += var * (ll)(v[i].SS - last_show[id].SS);
            }
            else{
                resp += fix + var * (ll)(v[i].SS-v[i].FF);
            }
            resp %= MOD;

            last_show[id] = v[i];
            tvs.insert({v[i].SS, id});
        }
    }

    cout << resp << endl;

    return 0;
}
