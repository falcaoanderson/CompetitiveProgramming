// 01/11/20 // 3:16 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;
const int MOD = (1e9) + 7;

char ma[MAXN][MAXN];
ll memo[MAXN][MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> ma[i][j];
    
    memo[1][1] = (ma[1][1]!='*');

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            if((i==1 && j==1) || ma[i][j]=='*') continue;

            memo[i][j] = (memo[i][j-1] + memo[i-1][j])%MOD;
        }
    
    cout << memo[n][n] << endl;

    return 0;
}
