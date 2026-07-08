/*
22/04/26 

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
    int n, m;
    cin >> n >> m;

    vector<int> dt(n);
    for(int i=0; i<n; i++) cin >> dt[i];
    set<pii> person;
    int max_t = 0;
    for(int i=0; i<m; i++){
        int t;
        cin >> t;
        person.insert({t, i});
        max_t = max(max_t, t + n - 1);
    }

    vector<int> ans_room(m, -1), ans_time(m, -1);
    for(int i=0; i<n && !person.empty(); i++){
        int st = 0;
        // cout << "room: " << i << " # ";
        while(st <= max_t){
            // cout << st << " ";
            auto it = person.lower_bound({st-i, 0});
            // it->first + i >= st

            if(it == person.end()) break;
            
            if(it->first + i < st + dt[i]){
                ans_room[it->second] = i;
                ans_time[it->second] = it->first + i;
            
                st = it->first + i + 1 + dt[i];

                person.erase(it);
            }
            else{
                st += 2*dt[i];
            }
        }
        // cout << endl;
    }

    for(int i=0; i<m; i++){
        cout << ans_room[i] << " " << ans_time[i] << endl;
    }
}

int main(){
    fast_io;

    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
