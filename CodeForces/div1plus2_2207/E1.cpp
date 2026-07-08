/*
11/03/26 

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

int n, bit[MAXN];

int query(int idx){
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

void update(int idx, int delta = 1){
    while(idx <= n + 1){
        bit[idx] += delta;
        idx += (idx & (-idx));
    }
}

void solve(){
    cin >> n;

    set<int> available;
    for(int i=1; i<=n; i++){
        bit[i] = 0;
        available.insert(i);
    }
    bit[n+1] = 0;

    bool ans = 1;
    vector<int> a(n), last_pos(n+2), vans(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]++;

        if(ans && a[i] <= n + 1 && (i==0 || a[i-1] >= a[i-1])){
            last_pos[a[i]] = i;
            
            if(available.find(a[i]) != available.end()){
                available.erase(a[i]);
            }
        }
        else{
            ans = 0;
        }
    }

    for(int i=0; i<n && ans; i++){
        int aux = query(a[i]) + n-i;

        if(aux == a[i]){
            vans[i] = a[0] + 1;
        }
        else if(aux + 1 == a[i]){
            auto it_max = available.lower_bound(a[i]);

            if(it_max == available.begin()){
                ans = 0;
                break;
            }

            it_max--;
            vans[i] = *it_max;

            available.erase(vans[i]);
            update(vans[i]);
        }
        else{
            ans = 0;
            break;
        }

        if(last_pos[a[i]] == i){
            available.insert(a[i]);
        }
    }

    if(ans){
        cout << "YES" << endl;
        for(int x: vans) cout << x - 1 << " ";
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
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
