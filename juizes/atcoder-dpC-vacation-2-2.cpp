// 02/01/29 // 4:25 AM //
// O(n)

#include <iostream>

using namespace std;

#define MAXN 100010

int n;
int value[MAXN][10];
int memo[5][5];

int solve(){  // ant = 0, 1, 2


    for(int i=1; i<=n; i++)
        for(int k=0; k<3; k++)
            for(int j=0; j<3; j++)
                if(j!=k)
                   memo[i&1][k] = max(memo[i&1][k], memo[~i&1][j] + value[i][k]);


    return max(memo[n&1][0], max(memo[n&1][1], memo[n&1][2]));
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> value[i][0] >> value[i][1] >> value[i][2];

    cout << solve() << "\n";

    return 0;
}

