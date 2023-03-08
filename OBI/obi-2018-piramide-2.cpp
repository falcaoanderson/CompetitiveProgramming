// 8/12/19 // 12:11 AM//

#include <bits/stdc++.h>

using namespace std;

#define MAXN 110
#define INF 0x3f3f3f3f

int n;
int ma[MAXN][MAXN];
int memo[MAXN][MAXN];

int solve(int esq, int dir, int nivel){
    if(memo[esq][dir]>-1) return memo[esq][dir];

    if(nivel==1) return memo[esq][dir] = 0;

    int op_esq = INF, op_dir = INF;

    if(esq < n) op_esq = ma[nivel-1][dir]   - ma[nivel-1][esq]     + solve(esq+1,   dir, nivel-1);
    if(dir > 1) op_dir = ma[nivel-1][dir-1] - ma[nivel-1][esq-1]   + solve(  esq, dir-1, nivel-1);


    return memo[esq][dir] = min(op_esq, op_dir);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin >> ma[i][j];
            ma[i][j] += ma[i][j-1];
        }

    cout << solve(1, n, n) + ma[n][n] << "\n";

    return 0;
}

