#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

vector<int> adj[MAXN];
int memo[MAXN][5];

int dfs(int u, int flag, int last){
    if(memo[u][flag]!=-1) return memo[u][flag];

    if(u==1){
        memo[u][flag] = 0;

        for(int v: adj[u]){
            if(v==last) continue;

            memo[u][flag] += dfs(v, 2, u);
        }

        return memo[u][flag];
    }

    if((int)adj[u].size()==1) return memo[u][flag] = (flag==0);

    int aux = 0;
    for(int v: adj[u]){
        if(v==last) continue;

        aux += min(dfs(v, (flag==2?1:0), u), dfs(v, 2, u) + 1);
    }

    if(flag==0){
        memo[u][flag] = INF;

        for(int v: adj[u]){
            if(v==last) continue;

            memo[u][flag] = min(memo[u][flag], aux - min(dfs(v, (flag==2?1:0), u), dfs(v, 2, u) + 1) + dfs(v, 2, u) + 1);
        }
    }
    else{
        memo[u][flag] = aux;
    }

    return memo[u][flag];
}

int main(){
    fast_io;    

    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }

    memset(memo, -1, sizeof(memo));
    
    cout << dfs(1, 2, 0) << endl;

    return 0;
}
