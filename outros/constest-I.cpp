#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;
const int INF  = 0x3f3f3f3f;

string palavra;
int memo[MAXN][MAXN];

int solve(int i, int j){
    if(memo[i][j]!=-1) return memo[i][j];

    if (j<i) return memo[i][j] = 0;
    if(i==j && palavra[i]!='a') return memo[i][j] = 1;

    int op1 = 0, op2, op3;

    if(palavra[i]==palavra[j] && palavra[i]!='a' && palavra[j]!='a')
        op1 = solve(i+1, j-1) + 2;

    op2 = solve(i+1, j);
    op3 = solve(i, j-1);

    return memo[i][j] = max(op1, max(op2, op3));
}

int main(){

    memset(memo, -1, sizeof(memo));

    cin >> palavra;

    cout << solve(0, (int)palavra.size() -1) << endl;

    return 0;
}
