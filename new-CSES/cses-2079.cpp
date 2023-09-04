// 04/09/23 //
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

int n, sz[MAXN];
vector<int> adj[MAXN];
int centroid=0;

void dfs(int u, int last){
    sz[u] = 1;

    for(int v: adj[u]){
        if(v==last) continue;

        dfs(v, u);
        sz[u] += sz[v];
    }

    bool is_centroid = ((n - sz[u]) <= (n/2));

    for(int v: adj[u]){
        if(v==last) continue;

        is_centroid = (is_centroid && (sz[v] <= (n/2)));
    }

    if(is_centroid) centroid = u;
}

int main(){
    fast_io;
    
    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }

    dfs(1, 0);

    cout << centroid << endl;

    return 0;
}
