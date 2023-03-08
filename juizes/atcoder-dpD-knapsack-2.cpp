// 29/07/19 // 7:10 PM //

#include <iostream>

using namespace std;

#define MAXN 110
#define MAXW 100010

int n, w;
int weight[MAXN], value[MAXN];

long long memo[MAXN][MAXW];

long long knapsack(){

    for(int i=1; i<=n; i++){
        for(int j=0; j<=w; j++){
            memo[i][j] = memo[i-1][j];

            if(j>=weight[i])
                memo[i][j] = max(memo[i][j], value[i] + memo[i-1][ j-weight[i] ]);
        }
    }

    return memo[n][w];
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;

    for(int i=1; i<=n; i++)
        cin >> weight[i] >> value[i];

    cout << knapsack() << "\n";

    return 0;
}

