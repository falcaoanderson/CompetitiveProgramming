// 12/09/23 //
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

int n, degree[MAXN];
unordered_set<int> adj[MAXN];
vector<int> path;

void dfs(int u){    
    while(!adj[u].empty()){
        int v = *adj[u].begin();

        adj[u].erase(v);
        adj[v].erase(u);

        dfs(v);
    }

    path.PB(u);
}

int main(){
    fast_io;

    int m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].insert(b);
        adj[b].insert(a);

        degree[a]++;
        degree[b]++;
    }

    for(int i=1; i<=n; i++){
        if(degree[i]&1){
            cout << "IMPOSSIBLE" << endl;
            return 0; 
        }
    }
    
    dfs(1);

    for(int i=1; i<=n; i++){
        if(!adj[i].empty()){
            cout << "IMPOSSIBLE" << endl;
            return 0; 
        }
    }
    
    for(int u: path) cout << u << " ";
    cout << endl;
    
    return 0;
}
