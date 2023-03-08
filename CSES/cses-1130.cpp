// 20/11/20 // xx:xx PM //

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
const int MAXN = (2e5) + 10;

int n;
vector<int> adj[MAXN];
int memo[MAXN][5];

int solve(int u, int pa, bool flag){
    if(memo[u][flag]!=-1) return memo[u][flag];
    
    int& ans = memo[u][flag];
    ans = 0;

    for(int v: adj[u])
        if(v!=pa) ans += solve(v, u, 1);
    
    if(flag){
        int temp = ans;
        
        for(int v: adj[u])
            if(v!=pa) temp = max(temp, ans - solve(v, u, 1) + solve(v, u, 0) + 1);
        
        ans = temp;
    }

    return ans;
}

int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    memset(memo, -1, sizeof(memo));

    cout << solve(1, 0, 1) << endl;

    return 0;
}
