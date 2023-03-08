// 20/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define ll long long

const int MAXN = (2e5) + 10;

int n;
vector<int> adj[MAXN];
ll sum_dist[MAXN], qnt[MAXN];

void pre_dfs(int u, int pa){
    qnt[u] = 1LL;
    for(int v: adj[u]){
        if(v==pa) continue;

        pre_dfs(v, u);

        qnt[u] += qnt[v];
    }
    
    sum_dist[u] = qnt[u]-1LL;
    for(int v: adj[u])
        if(v!=pa)
            sum_dist[u] += sum_dist[v];
    
}

void dfs(int u, int pa){

    if(u!=1) sum_dist[u] = sum_dist[pa] -2LL*qnt[u] + n;

    for(int v: adj[u])
        if(v!=pa) dfs(v, u);
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

    pre_dfs(1, 0);
    dfs(1, 0);

    for(int i=1; i<=n; i++)
        cout << sum_dist[i] << " ";
    cout << endl;

    return 0;
}
