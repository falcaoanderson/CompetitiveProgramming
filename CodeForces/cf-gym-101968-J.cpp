/*
27/02/24 
Problem: 2018 AICCSA Programming Contest - Restricted Vertex Cover
Complexity: O(n+m)
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int qnt_color, color[MAXN];
vector<int> adj[MAXN], adj_t[MAXN];
stack<int> dfs_order;

void dfs1(int u){
    color[u] = 1;

    for(int v: adj[u]){
        if(color[v]==0) dfs1(v);
    }

    dfs_order.push(u);
}

void dfs2(int u){
    for(int v: adj_t[u]){
        if(color[v]==0){
            color[v] = color[u];
            dfs2(v);
        }
    }
}

void add_edges(int a, bool neg_a, int b, bool neg_b){
    a = 2*a + neg_a;
    b = 2*b + neg_b;

    adj[a^1].PB(b);
    adj[b^1].PB(a);
    
    adj_t[b].PB(a^1);
    adj_t[a].PB(b^1);
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        for(int i=0; i<2*n; i++){
            adj[i].clear();
            adj_t[i].clear();
        }

        for(int i=0; i<m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;

            if(c==0){
                add_edges(a, 0, b, 0);
            }
            else{
                add_edges(a, 0, b, 0);
                add_edges(a, 1, b, 1);
            }
        }

        memset(color, 0, sizeof(color));
        for(int u=0; u<2*n; u++){
            if(color[u]==0) dfs1(u);
        }
        
        memset(color, 0, sizeof(color));
        qnt_color = 0;

        while(!dfs_order.empty()){
            int u = dfs_order.top();
            dfs_order.pop();

            if(color[u]==0){
                color[u] = (++qnt_color);
                dfs2(u);
            }
        }

        bool resp = 1;
        for(int i=0; i<n && resp; i++){
            int u = 2*i;
            resp = (color[u]!=color[u^1]);
        }

        cout << (resp?"YES":"NO") << endl;
    }

    return 0;
}