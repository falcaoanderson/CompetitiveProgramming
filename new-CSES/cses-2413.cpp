/*
16/08/24 
Problem: 
Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e6) + 5;
const int MOD  = (1e9) + 7;

int memo[MAXN][10];

int solve(int n, int last){
    if(memo[n][last]!=-1){
        return memo[n][last];
    }

    if(n==0){
        return memo[n][last] = 1;
    }
    
    if(last==1){
        return memo[n][last] = (solve(n-1, 1) + (n>1? solve(n-1, 5): 0))%MOD;
    }
    else if(last<=2 || last<=4){
        return memo[n][last] = (solve(n-1, 3) + (n>1? (solve(n-1, 2) + solve(n-1, 4))%MOD + solve(n-1, 6): 0)%MOD)%MOD;
    }
    else{
        return memo[n][last] = ((solve(n-1, 1) + solve(n-1, 3))%MOD + (n>1? (solve(n-1, 2) + solve(n-1, 4))%MOD + (solve(n-1, 5)+ solve(n-1, 6))%MOD: 0)%MOD)%MOD;
    }
}

int main(){
    fast_io;
    
    int t;
    cin >> t;

    memset(memo, -1, sizeof(memo));

    while(t--){
        int n;
        cin >> n;

        cout << solve(n, 5) << endl;
    }

    return 0;
}
