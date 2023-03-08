// 26/01/20 // 10:06 AM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(1e2) + 10;
const int MAXK = (int)(1e5) + 10;

int n, k;
int a[MAXN], memo[MAXK];

int solve(int h){
    if(memo[h]!=-1) return memo[h];

    if(!h) return memo[h] = 0;

    memo[h] = 0;

    for(int i=0; i<n && a[i]<=h; i++){
        memo[h] = !solve(h-a[i]);

        if(memo[h]) break;
    }

    return memo[h];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> a[i];

    cout << (solve(k)?"First":"Second") << endl;

    return 0;
}
