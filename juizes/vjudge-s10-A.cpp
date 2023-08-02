// 01/08/23 //
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

const int MAXN = (2e5) + 5;

vector<int> adj[MAXN];
bool visited[MAXN];

bool dfs(int u){
    visited[u] = 1;

    bool flag = ((int)adj[u].size()==2);

    for(int v: adj[u]){
        if(visited[v]) continue;

        flag = (dfs(v) && flag);
    }

    return flag;
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    while(m--){
        int u, v;
        cin >> u >> v;

        adj[u].PB(v);
        adj[v].PB(u);
    }

    int resp = 0;

    for(int i=1; i<=n; i++)
        if(!visited[i] && dfs(i)) resp++;
    
    cout << resp << endl;

    return 0;
}
