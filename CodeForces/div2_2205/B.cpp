/*
26/02/26 

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
    int n;
    cin >> n;

    vector<int> ans;
    for(int i=2; i*i<=n; i++){
        if((n % i) == 0){
            int a = i;
            bool flag = 1;
            for(int x: ans){
                if((a % x) == 0) flag = 0;
            }
            if(flag){
                ans.PB(a);
            }
        }
    }
    for(int i=2; i*i<=n; i++){
        if((n % i) == 0){
            int a = n / i;
            bool flag = 1;
            for(int x: ans){
                if((a % x) == 0) flag = 0;
            }
            if(flag){
                ans.PB(a);
            }
        }
    }
    
    if(ans.empty()){
        cout << n << endl;
        return;
    } 
    int val = 1;
    for(int x: ans) val *= x;
    cout << val << endl;
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
