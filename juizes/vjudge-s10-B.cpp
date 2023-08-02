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

int n, tree[MAXN], pos_tree[MAXN], sz_tree[MAXN], ind_tree=0;
vector<int> adj[MAXN];

void dfs(int u){
    tree[++ind_tree] = u;
    pos_tree[u] = ind_tree;
    sz_tree[u] = 1;

    for(int v: adj[u]){
        dfs(v);

        sz_tree[u] += sz_tree[v];
    }
}

int main(){
    fast_io;
    
    int n, q;
    cin >> n >> q;

    for(int i=2; i<=n; i++){
        int p;
        cin >> p;

        adj[p].PB(i);
    }

    for(int i=1; i<=n; i++) sort(adj[i].begin(), adj[i].end());

    dfs(1);

    while(q--){
        int u, k;
        cin >> u >> k;

        if(k <= sz_tree[u]){
            cout << tree[pos_tree[u]+k-1] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }

    return 0;
}
