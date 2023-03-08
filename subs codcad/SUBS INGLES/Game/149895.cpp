// 03/09/19 // 6:07 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define INF 0x3f3f3f3f

int n, v[MAXN], total=0;
int memo[MAXN][MAXN];

int solve(int l, int r){
    if(memo[l][r]>=0) return memo[l][r];

    if(l>r) return 0;
    if(l==r) return v[l];



    return memo[l][r] = max(v[l] + min(solve(l+2, r), solve(l+1, r-1)),
                            v[r] + min(solve(l+1, r-1), solve(l, r-2)));
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

    int temp = solve(1, n);
    int temp2 = total - temp;
    if(temp<temp2) swap(temp, temp2);

    cout << temp << " " << temp2 << "\n";

    return 0;
}
