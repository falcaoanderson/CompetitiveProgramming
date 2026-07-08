/*
27/03/26 

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
const ll MOD  = 998'244'353;
ll bit_sum[MAXN], bit_idx[MAXN];

ll query(int i, ll* bit){
    ll sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & (-i));
    }
    return sum;
}

int bsearch(ll val, int n, ll* bit){
    int idx = 0;
    for(int i = 17; i>=0; i--){
        if(idx + (1<<i) <= n && bit[idx + (1<<i)] < val){
            idx += (1<<i);
            val -= bit[idx];
        }
    }
    return idx + 1;
}

void update(int i, int n, ll delta, ll* bit){
    while(i <= n){
        bit[i] += delta;
        i += (i & (-i));
    }
}

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

void solve(){
    int n;
    cin >> n;

    vector<ll> v(n);
    vector<pair<ll, int>> aux(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        aux[i] = {v[i], i};
    }
    sort(aux.begin(), aux.end());
    vector<int> pos(n);
    for(int i=0; i<n; i++){
        pos[aux[i].SS] = i + 1;
    }

    ll sum = 0;
    for(int i=0; i<3; i++){
        sum += v[i];
        update(pos[i], n, 1, bit_idx);
        update(pos[i], n, v[i], bit_sum);
    }
    cout << 0 << endl;

    auto func = [n](ll m, ll sum, int i){
        ll left = -1, right = -1;

        if(m <= 1){
            left = 0;
        }
        else{
            ll m_idx = bsearch(m - 1, n, bit_idx);    
            ll m_sum = query(m_idx, bit_sum);
            ll m_val = query(m_idx, bit_sum) - query(m_idx - 1, bit_sum);
            
            left = (m - 1) * m_val - m_sum;
        }

        if(m >= i){
            right = 0;
        }
        else{
            ll m_idx = bsearch(m + 1, n, bit_idx);    
            ll m_sum = query(m_idx, bit_sum);
            ll m_val = query(m_idx, bit_sum) - query(m_idx - 1, bit_sum);
            
            right = (sum - m_sum) - (ll)(i+1 - (m + 1)) * m_val;
        }
        // cout << "left, right: " << left << " " << right << endl; 
        return max(left, right);
    };

    for(int i=3; i<n; i++){
        sum += v[i];
        update(pos[i], n, 1, bit_idx);
        update(pos[i], n, v[i], bit_sum);

        ll ans = LINF, l = 1, r = i+1;
        while(l <= r){
            ll m1 = l + (r - l) / 3;
            ll m2 = r - (r - l) / 3;
            
            ll m1_val = func(m1, sum, i), m2_val = func(m2, sum, i);
            
            if(m1_val < m2_val){
                ans = min(ans, m1_val);
                r = m2 - 1LL;
            }
            else{
                ans = min(ans, m2_val);
                l = m1 + 1LL;
            }
        }
        
        cout << (ans % MOD * exp(i-1, MOD-2)) % MOD << endl;
    }
}

int main(){
    fast_io;

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}