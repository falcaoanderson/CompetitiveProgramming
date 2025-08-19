/*
18/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int n, q, root=0, lvl[MAXN];
int logn, timer;
vector<vector<int>> adj, up;
vector<int> tin, tout;

void dfs(int v, int p){
    tin[v] = ++timer;
    
    up[v][0] = p;
    for(int i = 1; i <= logn; ++i) up[v][i] = up[up[v][i-1]][i-1];

    for(int u : adj[v]) {
        if (u == p) continue;

        lvl[u] = lvl[v]+1;
        dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = logn; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    logn = ceil(log2(n));
    up.assign(n, vector<int>(logn + 1));
    lvl[root] = 1;
    dfs(root, root);
}

int dist(int u, int v){
    return lvl[u]+lvl[v]-2*lvl[lca(u, v)];
}

// int solve(int a1, int b1, int a2, int b2){
//     if(lvl[b1]>lvl[a1]) swap(a1, b1);
//     if(lvl[b2]>lvl[a2]) swap(a2, b2);

//     if(b1==root && b2==root){
//         cout << "a" << endl;
//         return lvl[lca(a1, a2)];
//     }

//     int l1 = lca(a1, b1), l2 = lca(a2, b2);

//     if(b1==l1 && b2==l2){
//         if(l1==root){
//             cout << "b" << endl;
//             return solve(a1, l1, a2, root) - solve(a1, l1, up[l2][0], root);
//         }
//         cout << "c" << endl;
//         return solve(a1, root, a2, l2) - solve(up[l1][0], root, a2, l2);
//     }

//     if(b1==l1){
//         cout << "d" << endl;
//         return solve(a1, l1, a2, l2) + solve(a1, l1, b2, l2) - (lca(a1, l2)==l2 && lca(l2, l1)==l1);
//     }
//     if(b2==l2){
//         cout << "e" << endl;
//         return solve(a1, l1, a2, l2) + solve(b1, l1, a2, l2) - (lca(a2, l1)==l1 && lca(l1, l2)==l2);
//     }
//     cout << "f" << endl;
//     return solve(a1, l1, a2, l2) + solve(a1, l1, b2, l2) + solve(b1, l1, a2, l2) + solve(b1, l1, b2, l2) -(l1==l2? 3: 0);
// }

int main(){
    fast_io;

    cin >> n >> q;

    adj.assign(n, vector<int>());
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;

        adj[u-1].PB(v-1);
        adj[v-1].PB(u-1);
    }

    for(int i=0; i<n; i++){
        if(adj[i].size()>1){
            root = i;
            break;
        }
    }

    preprocess(root);

    while(q--){
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;

        a1--;a2--;b1--;b2--;

        int total = dist(a1, b1) + dist(a2, b2);
        int out = min(dist(a1, a2) + dist(b1, b2), dist(a1, b2) + dist(b1, a2));

        cout << (total>=out? (total-out)/2+1: 0) << endl;
    }

    return 0;
}
