#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 25;
const int MAXMASK = (1<<21)+10;
const int MOD = int(1e9) + 7;

int n;
bool comp[MAXN][MAXN];
int memo[MAXMASK];

int solve(int i, int mask){
    if(memo[mask]!=-1) return memo[mask];

    if(i>=n) return (mask==((1<<n)-1));

    memo[mask] = 0;
    for(int j=0; j<n; j++){
        if(comp[i][j] && (mask&(1<<j))==0){
            memo[mask] = (memo[mask]+solve(i+1, mask|(1<<j)))%MOD;
        }
    }

    return memo[mask];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> comp[i][j];

    memset(memo, -1, sizeof(memo));

    cout << solve(0, 0) << endl;

    return 0;
}
