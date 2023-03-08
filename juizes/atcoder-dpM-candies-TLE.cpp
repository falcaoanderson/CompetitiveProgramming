// 01/02/20 // 5:08 PM //
// complexity: O(n*k^2)

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = (int)1e2 + 10;
const int MAXK = (int)1e5 + 10;
const int MOD  = (int)1e9 + 7;

int n, k, a[MAXN];
int memo[MAXN][MAXK];

int solve(int i, int candie){
    if(memo[i][candie]!=-1) return memo[i][candie];

    if(candie==0) return 1;
    if(i==1)      return (a[i]>=candie);

    memo[i][candie] = 0;

    for(int l=0; l<=candie && l<=a[i]; l++)
        memo[i][candie] += solve(i-1, candie-l);

    return memo[i][candie];
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=0; i<=n; i++)            memo[i][0] = 1;
    for(int j=0; j<=k && j<=a[1]; j++) memo[1][j] = 1;

    for(int i=2; i<=n; i++){

        for(int j=1; j<=k; j++){

           for(int l=0; l<=min(a[i],j); l++){
                memo[i][j] += memo[i-1][j-l];
           }
           // soma do memo[i-1][j] ate memo[i-1][j-min(a[i], j)]
           // prefix[j] - prefix[j-min(a[i],j)-1]
        }
    }

    cout << memo[n][k] << endl;

    return 0;
}

