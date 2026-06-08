/*
30/01/26

*/
#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

vector<bool> visited;void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}

void strongly_connected_components(vector<vector<int>> const& adj,
                                  vector<vector<int>> &components) {
    int n = adj.size();
    components.clear();

    vector<int> order;

    visited.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0);

    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *component.begin();
            for (auto u : component)
                roots[u] = root;
        }
}

int main(){
    fast_io;

    int n, m;
    cin >> n;
    
    vector<int> cost(n);
    vector<vector<int>> adj(n);

    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].PB(b-1);
    }

    vector<vector<int>> components;

    strongly_connected_components(adj, components);
    
    ll total_cost=0, num=1;
    for(vector<int> &v: components){
        int mincost=INF, q=0;

        for(int x: v){
            if(cost[x] < mincost){
                mincost = cost[x];
                q = 1;
            }
            else if (cost[x] == mincost){
                q++;
            }
        }

        total_cost += (ll)mincost;
        num = (num * (ll)q) %  MOD;
    }

    cout << total_cost << " " << num << endl;

    return 0;
}