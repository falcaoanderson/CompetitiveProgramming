// 02/11/20 // xx:xx PM //

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
const int MAXN = (5e3) + 10;

string sa, sb;
int ta, tb, memo[MAXN][MAXN];

int min(int a, int b, int c){return min(a, min(b, c));}

int solve(int i, int j){ 

    if(memo[i][j] != -1) return memo[i][j];

    if(i==ta && j==tb) return 0;
    if(i==ta) return memo[i][j] = tb-j;
    if(j==tb) return memo[i][j] = ta-i;

    if(sa[i]==sb[j]) return memo[i][j] = solve(i+1, j+1);

    return memo[i][j] = min(solve(i, j+1)+1, solve(i+1, j)+1, solve(i+1, j+1)+1);
}

int main(){
    fast_io;
    
    cin >> sa >> sb;
    ta = sa.size();
    tb = sb.size();

    memset(memo, -1, sizeof(memo));

    cout << solve(0, 0) << endl;
    
    return 0;
}
