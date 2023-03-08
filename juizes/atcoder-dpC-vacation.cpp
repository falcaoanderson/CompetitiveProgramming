// 27/07/19 // 16:32 PM //
// O(n)

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 100010

int n;
int value[MAXN][10];
int memo[MAXN][10];

int funcao(int i, int ant){  // ant = 0, 1, 2
    if(memo[i][ant]>=0) return memo[i][ant];

    if(i>n) return 0;

    for(int k=0; k<3; k++)
        if(k!=ant)
            memo[i][ant] = max(memo[i][ant], value[i][k] + funcao(i+1, k));

    return memo[i][ant];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> value[i][0] >> value[i][1] >> value[i][2];

    cout << funcao(1, 4) << "\n";

    return 0;
}
