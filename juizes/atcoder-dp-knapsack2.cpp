// 30/07/19 // 9:04 PM //

#include <iostream>

using namespace std;

#define MAXN 110
#define MAXV 100010
#define INF 0x3f3f3f3f

int n, w;
int value[MAXN], weight[MAXN];
int memo[MAXN][MAXV+5];

void knapsack(){

    for(int j=0; j<=MAXV; j++)
        memo[0][j] = INF;
    memo[0][0] = 0;

    for(int i=1; i<=n; i++)
        for(int j=0; j<=MAXV; j++){
            memo[i][j] = memo[i-1][j];

            if(j-value[i]>=0)
                memo[i][j] = min(memo[i][j], weight[i] + memo[i-1][j-value[i]]);
        }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;
    for(int i=1; i<=n; i++)
        cin >> weight[i] >> value[i];


    knapsack();

    int resp = -1;

    for(int j=0; j<=MAXV; j++)
        if(memo[n][j]>0 && memo[n][j]<=w)
            resp = max(resp, j);

    cout << resp << "\n";


    return 0;
}
