// 03/09/19 // 6:07 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define INF 0x3f3f3f3f

int n, v[MAXN], total=0;
int memo[MAXN][MAXN][4];

int solve(int l, int r, int p){
    
    if(memo[l][r][p]>=0) return memo[l][r][p];
    
    if(l>r) return 0;
    if(l==r) return v[l];

    if(p==0)
        return memo[l][r][p] = min(solve(l+1, r, 1), solve(l, r-1, 1));
    else
        return memo[l][r][p] = max(v[l]+solve(l+1, r, 0), v[r] + solve(l, r-1, 0));

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        total += v[i];
    }

    int temp = solve(1, n, 0);
    int temp2 = total - temp;
    if(temp<temp2) swap(temp, temp2);

    cout << temp << " " << temp2 << "\n";

    return 0;
}