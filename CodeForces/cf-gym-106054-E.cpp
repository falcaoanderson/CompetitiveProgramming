/*
03/09/25 

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
#define SZ(x) (int)(x).size()

typedef pair<ll, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int n, val[MAXN];
vector<int> adj[MAXN];

int l, timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p){
          dfs(u, v);
        }
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int lca_v(vector<int> &nodes){
    if(SZ(nodes)==0) return 0;

    int crr = nodes[0];
    for(int i=1; i<SZ(nodes); i++){
        crr = lca(crr, nodes[i]);
    }
    // cout << crr << endl;    
    return crr;
}

pii solve(int root){
    pii resp = {0, 0};
    
    vector<int> lvl(n), aux;
    vector<ll> lvl_sum(n);
    queue<pii> fila;

    fila.push({root, 0});
    lvl_sum[0] = val[root];
    int crr_lvl=0;

    while(!fila.empty()){
        int u = fila.front().FF, p=fila.front().SS;
        fila.pop();
        // cout << u << " " << lvl[u] << endl;
        if(lvl[u]!=crr_lvl){
            if(lvl_sum[crr_lvl]>resp.FF){
                resp.FF = lvl_sum[crr_lvl];
                resp.SS = crr_lvl - lvl[lca_v(aux)];
            }
            else if(lvl_sum[crr_lvl]==resp.FF){
                resp.SS = min(resp.SS, crr_lvl - lvl[lca_v(aux)]);
            }
            aux.clear();
        }
        if(val[u]>0) aux.PB(u);
        crr_lvl = lvl[u];

        // cout << "v: "<< endl;
        for(int v: adj[u]){
            if(v==p) continue;
            // cout << v << " ";

            lvl[v] = lvl[u]+1;
            lvl_sum[lvl[v]] += val[v];

            fila.push({v, u});
        }
        // cout << endl << endl;
    }
    if(lvl_sum[crr_lvl]>resp.FF){
        resp.FF = lvl_sum[crr_lvl];
        resp.SS = crr_lvl - lvl[lca_v(aux)];
    }
    else if(lvl_sum[crr_lvl]==resp.FF){
        resp.SS = min(resp.SS, crr_lvl - lvl[lca_v(aux)]);
    }


    // cout << "lvl_sum:" << endl;
    // for(int i=0; i<5; i++) cout << lvl_sum[i] << endl;

    return resp;
}

int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<n; i++){
        cin >> val[i];
    }

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    // cout << endl << endl;

    preprocess(0);
    pii resp = {0, 0};
    for(int v: adj[0]){
        // cout << "root son: " << v << endl; 
        pii crr = solve(v);

        if(crr.FF > resp.FF || (crr.FF==resp.FF && crr.SS<resp.SS)){
            resp = crr;
        }
    }
    cout << resp.FF << " " << resp.SS+1 << endl;

    return 0;
}
