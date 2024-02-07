// 24/01/24
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
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

bool visited[MAXN];
vector<int> adj[MAXN], rev_adj[MAXN], dfs_order;
int qcolor, color[MAXN];

vector<int> rev_new_adj[MAXN], component[MAXN];

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
            rev_new_adj[qcolor].PB(color[v]);
        }
        if(color[v]==0){
            dfs2(v);
        }
    }
}

void dfs3(int u){
    visited[u] = 1;

    for(int v: rev_new_adj[u]){
        if(!visited[v]) dfs3(v);
    }
}

int main(){
    fast_io;
    
    int n, m;
    cin >> n >> m;

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
    
    memset(visited, 0, sizeof(visited));

    dfs3(qcolor);

    bool flag=1;
    for(int i=1; i<=qcolor && flag; i++) flag = visited[i];

    if(flag){
        cout << component[qcolor].size() << endl;

        sort(component[qcolor].begin(), component[qcolor].end());

        for(int v: component[qcolor]) cout << v << " ";
        cout << endl;
    }
    else{
        cout << 0 << endl;
    }

    return 0;
}
