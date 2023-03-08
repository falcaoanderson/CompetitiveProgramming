// 20/09/19 // 9:07 AM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010
#define MAXA 510
#define INF 0x3f3f3f3f

int p, a, prefix[MAXN];
int memo[10][MAXN], custo[MAXN][MAXN];

void solve(){

    // calcula os custos
    for(int ini=1; ini<=p; ini++){
        for(int fim=ini; fim<=p; fim++){
            custo[ini][fim] = (prefix[fim]-prefix[ini-1])*(fim-ini+1);
        }
    }

    // define os casos base
    for(int i=0; i<=a; i++)
        memo[i%2 + 1][p+1] = 0;
    for(int j=1; j<=p; j++)
        memo[2][j] = custo[j][p];

    // calcula dp
    for(int i=2; i<=a; i++){
        for(int j=1; j<=p; j++){

        memo[i%2 +1][j] = INF;
        for(int k=j; k<=p; k++)
            memo[i%2+1][j] = min(memo[i%2+1][j], memo[(i+1)%2 +1][k+1] + custo[j][k]);
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> p >> a;

    for(int i=1; i<=p; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    solve();

    cout << memo[a%2 +1][1] << "\n";

    return 0;
}

