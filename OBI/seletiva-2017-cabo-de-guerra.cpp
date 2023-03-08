// 01/11/19 // 9:34 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 60
#define INF  0x3f3f3f3f

int memo[MAXN][MAXN][MAXN*MAXN];

int n, v[MAXN], stotal;

int solve(int i, int qnt,int sum){
    if(memo[i][qnt][sum]>-1) return memo[i][qnt][sum];

    //cout << sum << "\n";

    if(qnt==(n/2)) return memo[i][qnt][sum] = abs(stotal-2*sum);
    if(i>n) return memo[i][qnt][sum] = INF;

    return memo[i][qnt][sum] = min(solve(i+1, qnt, sum),
                                   solve(i+1, qnt+1, sum+v[i]));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        stotal += v[i];
    }
    cout << solve(1,0,0) << "\n";

    return 0;
}
