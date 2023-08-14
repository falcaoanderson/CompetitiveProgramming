// 14/08/23 //
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

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (1e5) + 5;

int color[MAXN], qnt_color=0;
bool visited[MAXN];
vector<int> adj[MAXN], iadj[MAXN];
vector<int> process;

void dfs1(int u){
    visited[u] = 1;

    for(int v: adj[u]){
        if(!visited[v]) dfs1(v);
    }

    process.PB(u);
}

void dfs2(int u){
    color[u] = qnt_color;

    for(int v: iadj[u]){
        if(color[v]==0) dfs2(v);
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
        iadj[b].PB(a);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs1(i);
    }

    for(int i=n-1; i>=0; i--){
        int u = process[i];

        if(color[u]==0){
            qnt_color++;
            dfs2(u);
        }
    }

    cout << qnt_color << endl;
    for(int i=1; i<=n; i++) cout << color[i] << " ";
    cout << endl;

    return 0;
}
