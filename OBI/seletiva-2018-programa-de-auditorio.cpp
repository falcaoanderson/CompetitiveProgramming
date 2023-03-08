// 12/11/19 // 3:50 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 260
#define MAXV 250*250+10
#define pb push_back

int n, x;
int v[MAXN];
int memo[MAXN][MAXV];
vector<int> vsol;

int solve(int i, int sum){

    if(sum==0) return memo[i][sum] = 1;
    if(i>n || sum<0) return memo[i][sum] = 0;
    if(memo[i][sum]>=0) return memo[i][sum];


    if(solve(i+1, sum)) return memo[i][sum] = 1;
    if(solve(i+1, sum-v[i])){
        vsol.pb(i-1);
        return memo[i][sum] = 1;
    }

    return memo[i][sum] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n >> x;

    for(int i=1; i<=n; i++) cin >> v[i];

    if(solve(1, x)){
        cout << "S\n";

        for(int i=vsol.size()-1; i>=0; i--) cout << vsol[i] << " ";
        cout << "\n";
    }
    else{
        cout << "N\n";
    }

    return 0;
}
