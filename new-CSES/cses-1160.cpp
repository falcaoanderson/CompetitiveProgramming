/*
16/09/25 

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

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int n, adj[MAXN];
vector<int> revadj[MAXN];

int visited[MAXN];
int n_cycle, last[MAXN], cycle[MAXN], cycle_lvl[MAXN], cycle_sz[MAXN];
int tree[MAXN], tree_lvl[MAXN], in[MAXN], out[MAXN];

void dfs(int u){
    int v = adj[u];

    if(visited[v]==0){
        visited[v] = visited[u];
        last[v]    = u;

        dfs(v);
    }
    else if(visited[v]==visited[u] && cycle[v]==0){
        n_cycle++;

        int sz = 1, aux = u;
        while(aux!=v){
            sz++;
            aux = last[aux];
        }

        cycle_lvl[v] = 1;
        cycle[v]     = n_cycle;
        cycle_sz[v]  = sz;

        aux = u;
        int lvl=sz;
        while(aux!=v){
            cycle_lvl[aux] = lvl--;;
            cycle[aux]     = n_cycle;
            cycle_sz[aux]  = sz;        
            aux = last[aux];
        }
    }

    cycle[u] = cycle[v];
}

int tt=0;
void revdfs(int u){
    in[u] = ++tt;
    for(int v: revadj[u]){
        if(cycle_lvl[v]!=0) continue;

        tree[v] = tree[u];
        tree_lvl[v] = tree_lvl[u] + 1;
        revdfs(v);
    }
    out[u] = ++tt;
}

void pre_process(){
    for(int i=0; i<n; i++){
        if(visited[i]==0){
            visited[i] = i+1;
            dfs(i);
        }
    }

    for(int i=0; i<n; i++){
        if(cycle_lvl[i]!=0){
            tree[i] = i;
            revdfs(i);
        }
    }
}

int solve(int st, int ed){
    if(cycle[st]!=cycle[ed] || tree_lvl[st]>tree_lvl[ed]){
        return -1;
    }

    if(st==ed){
        return 0;
    }

    if(cycle_lvl[st]!=0){
        int aux = cycle_lvl[st]-cycle_lvl[tree[ed]];
        if(aux<0) aux += cycle_sz[st];

        return aux + tree_lvl[ed];
    }
    
    if(in[st]<in[ed] && out[ed]<out[st]){
        return tree_lvl[ed] - tree_lvl[st];
    }

    return -1;
}   

int main(){
    fast_io;

    int q;
    cin >> n >> q;

    for(int i=0; i<n; i++){
        int u;
        cin >> u;

        adj[i] = (u-1);
        revadj[u-1].PB(i);
    }

    pre_process();

    while(q--){
        int u, v;
        cin >> u >> v;

        cout << solve(v-1, u-1) << endl;
    }

    return 0;
}
