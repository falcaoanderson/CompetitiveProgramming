// 20/09/19 // 9:07 AM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010
#define MAXA 510
#define INF 0x3f3f3f3f

int p, a, prefix[MAXN];
int memo[MAXA][MAXN];

int custo(int ini, int fim){
    return (prefix[fim]-prefix[ini-1])*(fim-ini+1);
}

int solve(int f, int i){
    if(memo[f][i]>-1) return memo[f][i];

    if(i>p) return memo[f][i] = 0;

    if(f==1) return memo[f][i] = custo(i, p);

    memo[f][i] = INF;
    for(int k=i; k<=p; k++)
        memo[f][i] = min(memo[f][i], solve(f-1, k+1) + custo(i, k));


    return memo[f][i];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> p >> a;

    for(int i=1; i<=p; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    cout << solve(a, 1) << "\n";

    return 0;
}
