// 21/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define ll long long

const int MAXN = (2e5) + 10;

int n, color[MAXN], distinct[MAXN];
vector<int> adj[MAXN];
set<int> subtree[MAXN];

void dfs(int u, int pa){

    subtree[u].insert(color[u]);

    for(int v: adj[u]){
        if(v==pa) continue;

        dfs(v, u);

        if(subtree[v].size()>subtree[u].size()) swap(subtree[u], subtree[v]);

        subtree[u].insert(subtree[v].begin(), subtree[v].end());
    }

    distinct[u] = subtree[u].size();
}

int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> color[i];
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;
        
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0);
    
    for(int i=1; i<=n; i++)
        cout << distinct[i] << " ";
    cout << endl;

    return 0;
}
