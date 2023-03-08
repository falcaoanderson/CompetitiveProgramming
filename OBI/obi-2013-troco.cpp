// 31/05/20 // 8:08 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXV = (int)(1e5) + 10;
const int MAXN = (int)(1e3) + 10;

int v, n;
int coin[MAXN], memo[MAXN][MAXV];

bool solve(int i, int val){
    if(memo[i][val]!=-1) return memo[i][val];

    if(val == 0) return 1;
    if(i>n)      return 0;

    if(solve(i+1,val)) return memo[i][val] = 1;
    if(val-coin[i]>=0 && solve(i+1, val-coin[i])) return memo[i][val] = 1;

    return memo[i][val] = 0;
}

int main(){

    cin >> v >> n;
    for(int i=1; i<=n; i++) cin >> coin[i];

    memset(memo, -1, sizeof(memo));
    cout << (solve(1, v)?"S":"N") << endl;

    return 0;
}
