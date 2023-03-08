// 23/01/20 // 10:51 PM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(1e3) + 10;
const int INF  = 0x3f3f3f3f;
const int MOD  = (int)(1e9) + 7;

int h, w;
char grid[MAXN][MAXN];
int memo[MAXN][MAXN];

int solve(){

    memo[h][w]=1;

    for(int i=h; i>=1; i--){
        for(int j=w; j>=1; j--){
            if(grid[i][j]=='#' || (i==h && j==w)) continue;

            memo[i][j] = (memo[i+1][j] + memo[i][j+1])%MOD;
        }
    }


    return memo[1][1];
}

int main(){

    cin >> h >> w;

    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            cin >> grid[i][j];

    cout << solve() << endl;

    return 0;
}
