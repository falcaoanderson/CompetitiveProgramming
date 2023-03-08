// 17/07/20 // 11:29 PM //

#include <bits/stdc++.h>

using namespace std;

#define int long long

int const MAXN = 2e3 + 10;
int const INF = 0x3f3f3f3f;

int lpeso, n;
int w[MAXN], v[MAXN];
int memo[2][MAXN];

/*
int solve(int i, int peso){
    if(memo[i][peso]!=-1) return memo[i][peso];

    if(i>n || peso == 0) return 0;

    int pegar=-INF, nao_pegar;

    if(w[i] <= peso){
        pegar = v[i] + solve(i+1, peso-w[i]);
    }

    nao_pegar = solve(i+1, peso);

    return memo[i][peso] = max(pegar, nao_pegar);
}
*/

int32_t main(){

    cin >> lpeso >> n;

    for(int i=1; i<=n; i++) cin >> w[i] >> v[i];

    /*
    memset(memo, -1, sizeof(memo));

    cout << solve(1, lpeso) << endl;
    */

    for(int i=n; i>=1; i--){
        for(int peso=1; peso<=lpeso; peso++){

            memo[i&1][peso] = memo[~i&1][peso]; // nao pegar;

            if(w[i]<=peso) memo[i&1][peso] = max(memo[~i&1][peso], v[i] + memo[~i&1][peso-w[i]]);
        }
    }

    cout << memo[1][lpeso] << endl;

    return 0;
}
