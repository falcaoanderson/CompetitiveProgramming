/*
17/03/26 

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
    vector<int> x(n), y(n), idx(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), 
        [&y](int a, int b){
            return y[a] < y[b];
        }
    );
    vector<int> qx(m), qy(m), qidx(m);
    for(int i=0; i<m; i++){
        cin >> qx[i] >> qy[i];
        qidx[i] = i;
    }
    sort(qidx.begin(), qidx.end(), 
        [&qy](int a, int b){
            return qy[a] < qy[b];
        }
    );
    
    vector<ll> sum(n+1); ll max_sum = 0;
    vector<int> low(n+1), sz(n+1);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int j = n-1; j >= 0; j--){
        int i = idx[j], qnt = y[i];

        if(j < n-1 && y[idx[j+1]] != qnt){
            for(int it = y[idx[j+1]]-1; it >= qnt; it--){
                sum[it] = sum[it + 1];

                while(SZ(pq) > it + 1){
                    sum[it] -= (ll)pq.top();
                    pq.pop();
                }
                
                sz[it]  = pq.size();
                low[it] = pq.top();
            }
        }

        sum[qnt] += (ll)x[i];
        pq.push(x[i]);
        if(SZ(pq) > qnt + 1){
            sum[qnt] -= (ll)pq.top();
            pq.pop();
        }

        sz[qnt] = pq.size();
        low[qnt] = pq.top();
        max_sum = max(max_sum, sum[qnt]);
    }
    for(int it = y[idx[0]]-1; it >= 0; it--){
        sum[it] = sum[it + 1];

        while(SZ(pq) > it + 1){
            sum[it] -= (ll)pq.top();
            pq.pop();
        }
        
        sz[it]  = pq.size();
        low[it] = pq.top();
    }

    vector<ll> ans(m);
    ll ans_parc = 0; int crr_q = 0;
    for(int j=0; j<m; j++){
        int i = qidx[j], qnt = qy[i];

        while(crr_q <= qnt){
            ans_parc = max(ans_parc, sum[crr_q] - (ll)(sz[crr_q] < crr_q + 1? 0: low[crr_q]));
            crr_q++;
        } 

        ans[i] = max(max_sum, ans_parc + (ll)qx[i]);
    }

    for(ll val: ans) cout << val << " ";
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
