// 31/05/20 // 8:08 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXV = (int)(1e5) + 10;
const int MAXN = (int)(1e3) + 10;

int v, n;
int coin[MAXN], memo[3][MAXV];

void solve(){

    memo[0][0] = memo[1][0] =  1;

    for(int i=n; i>=1; i--){
        for(int j=1; j<=v; j++){

            if(j-coin[i]>=0) memo[i&1][j] = memo[(i+1)&1][j] || memo[(i+1)&1][j-coin[i]];
            else             memo[i&1][j] = memo[(i+1)&1][j];
        }
    }
}

int main(){

    cin >> v >> n;
    for(int i=1; i<=n; i++) cin >> coin[i];

    solve();

    cout << (memo[1][v]?"S":"N") << endl;

    return 0;
}

