/*
07/09/25 

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

int solve(int n, int k){
    if(k<=n/2){
        return 2*k;
    }
    if(k==(n+1)/2){
        return 1;
    }   

    return 2*solve(n/2, k-(n+1)/2) + (n&1? 1: -1);
}

int main(){
    fast_io;

    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;

        cout << solve(n, k) << endl;
    }

    return 0;
}
