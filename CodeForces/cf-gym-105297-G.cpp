// 24/08/24 // Virtual
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1e3 + 5;
const int INF = 0x3f3f3f3f;

int n;
ll x[MAXN];
ll memo[MAXN][MAXN];

ll solve(int i, int t){
    if(memo[i][t]!=-1) return memo[i][t];

    if(i==n+1) return 0;
    if(t<0) return INF;

    return memo[i][t] = min(abs(x[i]-x[i-1]) + solve(i+1, t), abs(x[t]-x[i]) + solve(i+1, i-1));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i];
    }

    memset(memo, -1, sizeof(memo));
    cout << solve(1, 0) << endl;

    return 0;
}