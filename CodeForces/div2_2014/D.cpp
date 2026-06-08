/*
24/01/26

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

void solve(){
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> st(k), ed(k);
    for(int i=0; i<k; i++){
        cin >> st[i] >> ed[i];
    }
    sort(st.begin(), st.end());
    sort(ed.begin(), ed.end());

    int b_col = -MAXN, m_col = MAXN, b_st = 0, m_st = 0;

    for(int i=1; i+d-1<=n; i++){
        int left = lower_bound(ed.begin(), ed.end(), i) - ed.begin();
        int right = k - (upper_bound(st.begin(), st.end(), i+d-1) - st.begin());
        int col = k - left - right;
        
        if(col > b_col){
            b_col = col;
            b_st = i;
        }
        if(col < m_col){
            m_col = col;
            m_st = i;
        }
    }

    cout << b_st << " " << m_st << endl;
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