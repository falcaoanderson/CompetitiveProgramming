#include <iostream>

using namespace std;

#define MAXN 110
#define MAXV 100010
#define INF 0x3f3f3f3f

int n, w;
int value[MAXN], weight[MAXN];
int dp[MAXN][MAXV+5];

void knapsack(){

    for(int j=0; j<=MAXV; j++){
        dp[0][j] = INF;
    }
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=MAXV; j++){
            dp[i][j] = dp[i-1][j];

            if(j-value[i]>=0) {
                dp[i][j] = min(dp[i][j], weight[i] + dp[i-1][j-value[i]]);
            }
        }
    }
}

int main(){

    cin >> n >> w;
    for(int i=1; i<=n; i++)
        cin >> weight[i] >> value[i];

    knapsack();

    int ans = 0;
    for (int i = 0; i<=MAXV; ++i) {
        if (dp[n][i] <= w) ans = i;
    }
    printf("%d\n", ans);
}
