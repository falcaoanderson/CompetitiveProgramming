// 20/08/21 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (5e2) + 10;

int n, tamc, tamb;
int cima[MAXN], baixo[MAXN];
int memo[MAXN][MAXN][MAXN];

int solve(int i, int a, int b){
    if(memo[i][a][b] != INF) return memo[i][a][b];

    if(i>n){
        if(a<=tamc || b<=tamb) return -INF;
        else                   return 0;
    }

    if(n-i+1 < tamc-a+1 || n-i+1 < tamb-b+1) return -INF;
    
    if(a>tamc || b>tamb) return 0;

    return memo[i][a][b] = max(solve(i+1, a+1, b+1) + cima[a]*baixo[b], max(solve(i+1, a+1, b), solve(i+1, a, b+1)));
}

int main(){
    fast_io;

    cin >> n;

    cin >> tamc;
    for(int i=1; i<=tamc; i++) cin >> cima[i];

    cin >> tamb;
    for(int i=1; i<=tamb; i++) cin >> baixo[i];

    memset(memo, INF, sizeof(memo));

    cout << solve(1, 1, 1) << endl;

    return 0;
}
