// 18/11/20 // xx:xx PM //

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
const int MAXN = 1e2 + 5;
const int MOD  = (1e9) + 7;

int n, a, b;
double memo[MAXN][6*MAXN];

double solve(int i, int sum){
    if(memo[i][sum]!=-1.0) return memo[i][sum];

    if(sum>b) return 0;

    if(i==n+1){
        if(a<=sum && sum<=b) return 1;
        else                 return 0;
    }

    double p = 0;
    for(int k=1; k<=6; k++){
        double x = 1.0/6.0;
        p += x * solve(i+1, sum+k);
    }

    return memo[i][sum] = p;
}

int main(){
    fast_io;

    cin >> n >> a >> b;

    for(int i=1; i<=n+1; i++){
        for(int j=0; j<=6*n; j++){
            memo[i][j] = -1.0;
        }
    }

    cout.precision(6);
    cout.setf(ios::fixed);

    cout << solve(1, 0) << endl;
    
    return 0;
}
