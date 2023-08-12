// 12/08/23 //
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

bool visited[MAXN];
int color[MAXN], qnt_color=0;
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

void dfs3(int u){
    visited[u] = 1;

    for(int v: adj[u]){
        if(!visited[v]) dfs3(v);
    }
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].PB(v);
        iadj[v].PB(u);
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

    if(qnt_color==1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;

        memset(visited, 0, sizeof(visited));
        dfs3(1);

        for(int i=2; i<=n; i++){
            if(color[i]!=color[1]){
                if(visited[i])
                    cout << i << " " << 1 << endl;
                else{
                    cout << 1 << " " << i << endl;
                }
            }
        }
    }

    return 0;
}