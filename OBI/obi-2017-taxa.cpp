// 18/09/19 // 6:58 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 210
#define INF 0x3f3f3f3f

int n;
int area[2*MAXN], prefix[2*MAXN];
int memo[2*MAXN][2*MAXN];
double fator;

int multa(int l, int i, int r){
    return max(prefix[i]-prefix[l-1], prefix[r]-prefix[i]);
}

int solve(int l, int r){
    if(memo[l][r]>-1) return memo[l][r];

    if(l==r) return memo[l][r] = 0;

    memo[l][r] = INF;

    for(int i=l; i<r; i++){
        memo[l][r] = min(memo[l][r], solve(l, i) + solve(i+1, r) + multa(l, i, r));
    }

    return memo[l][r];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> fator;

    for(int i=1; i<=n; i++){
        cin >> area[i];
        area[i+n]=area[i];
    }

    for(int i=1; i<=2*n; i++) prefix[i] = prefix[i-1] + area[i];

    int resp = INF;
    memset(memo, -1, sizeof(memo));
    for(int i=1; i<=n; i++){
        resp=min(resp, solve(i, i+n-1));
    }

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << resp*fator << "\n";

    return 0;
}
