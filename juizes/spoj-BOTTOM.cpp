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
const int MAXN = (5e3) + 5;
const int MOD  = (1e9) + 7;

bool visited[MAXN];
vector<int> adj[MAXN], rev_adj[MAXN], dfs_order;
int qcolor, color[MAXN];

bool isnot_sink[MAXN];
vector<int> component[MAXN];

void dfs1(int u){
    visited[u] = 1;

    for(int v: adj[u]){
        if(!visited[v]) dfs1(v);
    }

    dfs_order.PB(u);
}

void dfs2(int u){
    color[u] = qcolor;
    component[qcolor].PB(u);

    for(int v: rev_adj[u]){
        if(color[v]!=0 && color[v]!=qcolor){
            isnot_sink[color[v]] = 1;
        }
        if(color[v]==0){
            dfs2(v);
        }
    }
}

int main(){
    fast_io;
    
    while(true){
        int n, m;
        
        cin >> n;
        if(n==0) break;
        cin >> m;

        memset(visited, 0, sizeof(visited));
        memset(isnot_sink, 0, sizeof(isnot_sink));
        memset(color, 0, sizeof(color));
        dfs_order.clear();
        qcolor=0;
        for(int i=1; i<=n; i++){
            adj[i].clear();
            rev_adj[i].clear();
            component[i].clear();
        }

        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;

            adj[a].PB(b);
            rev_adj[b].PB(a);
        }

        for(int i=1; i<=n; i++){
            if(!visited[i]) dfs1(i);
        }

        for(int i=n-1; i>=0; i--){
            int u = dfs_order[i];

            if(color[u]==0){
                qcolor++;
                dfs2(u);
            }
        }

        vector<int> resp;
        for(int i=1; i<=qcolor; i++){
            if(!isnot_sink[i]){
                for(int u: component[i]) resp.PB(u);
            }
        }

        sort(resp.begin(), resp.end());
        for(int u: resp) cout << u << " ";
        cout << endl;
    }
    
    return 0;
}
