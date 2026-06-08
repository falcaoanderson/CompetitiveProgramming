/*
31/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){
    fast_io;

    int n, m, l;
    cin >> n >> m >> l;

    vector<pii> fish;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;

        if(y <= l) fish.PB({x, y});
    }
    vector<pii> men(m);
    for(int i=0; i<m; i++){
        cin >> men[i].FF;
        men[i].SS = i;
    }

    sort(fish.begin(), fish.end());
    sort(men.begin(), men.end());

    vector<int> qnt(m);
    for(pii f: fish){
        int a = f.FF, b = f.SS, st, ed;

        // cout << "l: " << a + (b - l) << " " << "r: " << l + (a - b) << endl; 

        st = lower_bound(men.begin(), men.end(), pii(a + (b - l), -1)) - men.begin();
        ed = upper_bound(men.begin(), men.end(), pii(l + (a - b), m)) - men.begin();
        // cout << st << " " << ed << endl;
        if(st<=ed && 0<=st && st<m && 0<ed){
            qnt[st]++;
            if(ed<m) qnt[ed]--;
        }
    }

    for(int i=1; i<m; i++){
        qnt[i] += qnt[i-1];
    }

    // cout << "pescadores:" << endl;;
    // for(int i=0; i<m; i++){
    //     cout << men[i].FF << " " << qnt[i] << endl;
    // }

    vector<int> ans(m);
    for(int i=0; i<m; i++) ans[men[i].SS] = qnt[i];
    for(int x: ans){
        cout << x << endl;
    }

    return 0;
}