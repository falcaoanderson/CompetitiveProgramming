/*
22/02/26 

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

void solve(int len, int n){
    vector<int> left(n), right(n), id(n);
    for(int i=0; i<n; i++){
        int x, r;
        cin >> x >> r;

        id[i] = i;
        left[i] = max(x - r, 0);
        right[i] = min(x + r, len);       
    }

    sort(id.begin(), id.end(), 
        [&left, &right](int a, int b){
            return left[a] < left[b] || (left[a] == left[b] && right[a] > right[b]);
        }  
    );

    int idx = 0, crr_r = 0, nxt_r = 0, count = 0; 
    if(left[id[0]] == 0){
        count = 1;
        crr_r = right[id[0]];
    }

    while(idx < n && crr_r < len && left[id[idx]] <= crr_r){
        count++;

        nxt_r = max(nxt_r, right[id[idx]]);        
        while(idx+1 < n && left[id[idx+1]] <= crr_r){
            nxt_r = max(nxt_r, right[id[++idx]]);
        }

        crr_r = nxt_r;
        idx++;
    }
    
    cout << (crr_r == len? n - count: -1) << endl;
}

int main(){
    fast_io;

    int len, n;
    while(1){
        cin >> len >> n;
        if(len == 0 && n == 0) break;

        solve(len, n);
    }

    return 0;
}
