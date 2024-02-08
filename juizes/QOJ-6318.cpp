// 27/01/24 //
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e2) + 5;
const int MAXV = (1e4) + 5;
const int MOD  = (1e9) + 7;

int n, v[MAXN];
int memo[MAXN][MAXV];

int solve(int i, int val){
    if(memo[i][val]!=-1) return memo[i][val];
    
    if(i>n || val==0) return 0;

    memo[i][val] = solve(i+1, val);

    string sval = to_string(val);
    sort(sval.begin(), sval.end());

    do{
        int new_val = stoi(sval);

        if(new_val>=v[i])
            memo[i][val] = max(memo[i][val], 1 + solve(i+1, new_val-v[i]));

    }while(next_permutation(sval.begin(), sval.end()));

    return memo[i][val];
}

int main(){
    fast_io;

    int x;
    cin >> n >> x;

    for(int i=1; i<=n; i++) cin >> v[i];
    
    memset(memo, -1, sizeof(memo));

    cout << solve(1, x) << endl;

    return 0;
}
