// 23/01/20 // 11:34 AM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(3e3) + 10;
const int INF  = 0x3f3f3f3f;

int n;
double p[MAXN], memo[MAXN][MAXN];

double solve(int i, int qnt){
    if(memo[i][qnt]!=-1) return memo[i][qnt];

    if(2*(qnt+n-i+1)<n) return memo[i][qnt] = 0;
    if(i>n)             return memo[i][qnt] = 1;

    return memo[i][qnt] = p[i]*solve(i+1, qnt+1) + (1-p[i])*solve(i+1, qnt);
}

int main(){


    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];

    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=n+1; j++)
            memo[i][j] = -1;


    cout.precision(10);
    cout.setf(ios::fixed);

    cout << solve(1, 0) << endl;

    return 0;
}
