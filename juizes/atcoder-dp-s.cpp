// 11/06/20 // 00:10 AM //

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = (int)(1e4) + 10;
const int MAXSUM = 110;
const int MOD = (int)(1e9)+7;

int d, n;
int num[MAXN], memo[MAXN][MAXSUM][3];

int solve(int i, int sum, int flag){
    if(memo[i][sum][flag] != -1) return memo[i][sum][flag];

    int& ans = memo[i][sum][flag];

    if(i>=n)
        return ans = (sum%d==0? 1: 0);

    ans = 0;
    if(!flag){
        for(int j=0; j<=9; j++){
            ans += solve(i+1, (sum+j)%d, 0)%MOD;
            ans %= MOD;
        }
    }
    else{
        for(int j=0; j<num[i]; j++){
            ans += solve(i+1, (sum+j)%d, 0)%MOD;
            ans %= MOD;
        }
        ans += solve(i+1, (sum+num[i])%d, 1)%MOD;
        ans %= MOD;
    }

    return ans;
}

int32_t main(){

    string temp;
    cin >> temp >> d;
    n = temp.size();

    for(int i=0; i<n; i++) num[i] = (int)(temp[i] - '0');

    memset(memo, -1, sizeof(memo));

    cout << (MOD+solve(0, 0, 1)-1)%MOD << endl;

    return 0;
}
