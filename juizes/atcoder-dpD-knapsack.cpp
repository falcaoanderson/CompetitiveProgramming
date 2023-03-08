// 29/07/19 // 7:10 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 110
#define MAXW 100010

int n, w;
int weight[MAXN], value[MAXN];

long long memo[MAXN][MAXW];

long long tknapsack(int i, int over){
    if(memo[i][over]>=0) return memo[i][over];

    if(i>n) return memo[i][over] = 0LL;

    long long take=0LL, dtake = tknapsack(i+1, over);

    if(over-weight[i]>=0)
        take = value[i] + tknapsack(i+1, over-weight[i]);

    return memo[i][over] = max(dtake, take);
}

long long knapsack(int i, int over){
    if(memo[i][over]>=0) return memo[i][over];

    if(i<1) return memo[i][over] = 0LL;

    long long temp = knapsack(i-1, over);

    if(over >= weight[i])
        temp = max(temp, value[i] + knapsack(i-1, over - weight[i]));

    return memo[i][over] = temp;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n >> w;

    for(int i=1; i<=n; i++)
        cin >> weight[i] >> value[i];

    cout << knapsack(n, w) << "\n";

    return 0;
}
