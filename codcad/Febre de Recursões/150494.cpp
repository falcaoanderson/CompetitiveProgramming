#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1010

int n, k, m, a[MAXN];
long long dp[MAXN];

long long func(int z){
    if(dp[z]!=-1)return dp[z];

    dp[z]=0;
    for(int i=1; i<=n; i++){
        dp[z] += (a[i]*func(z-i))%m;
        dp[z] = (dp[z])%m;
    }

    return dp[z];
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof(dp));

    cin >> n >> k >> m;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
        cin >> dp[i];

    cout << func(k) << "\n";

    return 0;
}