// 22/08/23 // 29/09/23
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

ll coin[MAXN], coin_color[MAXN], memo[MAXN];
vector<int> adj_ini[MAXN], rev_adj_ini[MAXN], adj_final[MAXN];
int color[MAXN], qcolor=0;

vector<int> path;
void dfs_a(int u){
    color[u] = 1;

    for(int v: adj_ini[u]){
        if(!color[v]) dfs_a(v);
    }

    path.PB(u);
}

void dfs_b(int u){
    for(int v: rev_adj_ini[u]){
        if(!color[v]){
            color[v] = color[u];
            dfs_b(v);
        }
    }
}

void dfs_c(int u){
    if(memo[u]!=0LL) return;

    ll aux=0;
    for(int v: adj_final[u]){
        if(memo[v]==0LL) dfs_c(v);

        aux = max(aux, memo[v]);
    }

    memo[u] = coin_color[u] + aux;
}


int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> coin[i];

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj_ini[a].PB(b);
        rev_adj_ini[b].PB(a);
    }

    for(int i=1; i<=n; i++){
        if(!color[i]) dfs_a(i);
    }

    memset(color, 0, sizeof(color));
    reverse(path.begin(), path.end());

    for(int u: path){
        if(!color[u]){
            color[u] = ++qcolor;
            dfs_b(u);
        }
    }

    for(int u=1; u<=n; u++){
        for(int v: adj_ini[u]){
            if(color[u]!=color[v]) 
                adj_final[color[u]].PB(color[v]);
        }
        coin_color[color[u]] += coin[u];
    }
    
    ll resp = 0;
    for(int i=1; i<=qcolor; i++){
        if(memo[i]==0LL) dfs_c(i);
        resp = max(resp, memo[i]);
    }
    cout << resp << endl;
    

    return 0;
}