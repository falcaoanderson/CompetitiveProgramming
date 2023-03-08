// 14/05/20 // 07:34 PM //

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define int long long

const int MOD  = (int)1e9+7;
const int MAXN = (int)1e5+10;

int n;
vector<int> graph[MAXN];
bool visited[MAXN];
int memo[MAXN][3];

void dfs(int v){

    visited[v] = 1;
    memo[v][0] = memo[v][1] = 1;

    for(int u : graph[v]){
        if(visited[u]) continue;

        dfs(u);

        memo[v][0] =  (memo[v][0] * (memo[u][0] + memo[u][1]))%MOD;
        memo[v][1] =  (memo[v][1] *  memo[u][0])%MOD;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;

        graph[x].pb(y);
        graph[y].pb(x);
    }

    dfs(1);
    int resp = (memo[1][0] + memo[1][1])%MOD;

    cout << resp << endl;

    return 0;
}
