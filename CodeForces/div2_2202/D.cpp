/*
16/03/26 

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

// int calc(vector<int>& v){
//     int n = SZ(v) / 2, q = 0;
//     vector<bool> prev(n+1); 
//     bool flag = 0;

//     for(int i=0; i < 2*n; i++){
//         if(prev[v[i]]){
//             if(flag && v[i] != v[i-1]){
//                 q += 2;
//             }
//             else{
//                 q++;
//             }
//             flag = 0;
//         }
//         else{
//             prev[v[i]] = 1;
//             if(flag){
//                 q++;
//                 flag = 0;
//             }
//             else{
//                 flag = 1;
//             }
//         }
//     }

//     return q;
// }

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> ans;
    if(n > k || k > 2 * n - 1){
        cout << "NO" << endl;
    }
    else if(k <= (n+1)/2 + n){
        cout << "YES" << endl;

        int m = min((k - n) * 2, n);
        for(int i=1; i <= m; i++) ans.PB(i);
        for(int i=1; i <= m; i++) ans.PB(i);
        for(int i = 1+m; i <= n; i++){
            ans.PB(i);
            ans.PB(i);
        }
    }
    else{
        cout << "YES" << endl;

        int m = (k - ((n+1) / 2 + n)) * 2 - (int)((n%2)==0);
        for(int i = 1; i <= n - m; i++) ans.PB(i);
        for(int i = 1; i <= n + m; i++){
            if(i <= 2 * m) ans.PB(i / 2 + (i&1? 1: n-m));
            else           ans.PB(i - m);
        }
    }

    if(!ans.empty()){
        for(int x: ans) cout << x << " ";
        cout << endl;
        // cout << "k, count = "    << k << " " << calc(ans) << endl;
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
