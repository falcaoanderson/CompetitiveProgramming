// 20/10/20 // 17:41 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e2) + 10;

int n, prefix[2*MAXN];
double f, memo[2*MAXN][2*MAXN];

double solve(int l, int r){
    if(memo[l][r]!=-1) return memo[l][r];

    if(l==r) return 0;

    memo[l][r] = INF;
    for(int i=l; i<r; i++){
        memo[l][r] = min(memo[l][r],
                         solve(l, i)+solve(i+1, r)+f*max(prefix[i]-prefix[l-1], prefix[r]-prefix[i]));
    }

    return memo[l][r];
}

int main(){
    fast_io;

    cin >> n >> f;

    for(int i=1; i<=n; i++){
        cin >> prefix[i];
        prefix[i+n] = prefix[i];
    }
    for(int i=1; i<=2*n; i++)
        prefix[i] += prefix[i-1];

    double resp = INF;

    for(int i=1; i<=2*n; i++)
        for(int j=1; j<=2*n; j++)
            memo[i][j] = -1;

    for(int i=1; i<=n; i++)
        resp = min(resp, solve(i, i+n-1));

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << resp << endl;

    return 0;
}

