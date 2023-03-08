// 22/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define ll long long

const int MAXN = (2e5) + 10;

int n, q, level[MAXN], first[MAXN], logg[3*MAXN], prefix[MAXN], aux[MAXN];
int tree[3*MAXN], table[3*MAXN][30], sz=0;
vector<int> adj[MAXN];

void dfs(int u, int pa){
    tree[++sz] = u;
    first[u] = sz;

    for(int v: adj[u]){
        if(v==pa) continue;

        level[v] = level[u] + 1;

        dfs(v, u);

        tree[++sz] = u;
    }
}

void lca_pre_processing(){
    dfs(1, 0);
    
    for(int i=1; i<=sz; i++) table[i][0] = tree[i];
        
    for(int j=1; j<22; j++){
        for(int i=1; i<=sz; i++){
            if(i+(1<<j)-1>sz) break;

            if(level[table[i][j-1]] < level[table[i+(1<<(j-1))][j-1]])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i+(1<<(j-1))][j-1];
        }
    }

   for(int i=2; i<=sz; i++) logg[i] = logg[i/2] + 1;
}

int lca(int a, int b){
    a = first[a];
    b = first[b];
    if(a>b) swap(a, b);

    int x = logg[b-a+1];

    if(level[table[a][x]] < level[table[b-(1<<x)+1][x]])
        return table[a][x];
    else 
        return table[b-(1<<x)+1][x];
}

void calc_dfs(int u, int pa){
    for(int v: adj[u]){
        if(v==pa) continue;

        calc_dfs(v, u);
        prefix[u] += prefix[v];
    } 
}

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    lca_pre_processing();

    while(q--){
        int a, b;
        cin >> a >> b;

        int c = lca(a, b);

        prefix[a]++; prefix[b]++; prefix[c]-=2;
        aux[c]++;
    }

    calc_dfs(1, 0);

    for(int i=1; i<=n; i++)
        cout << prefix[i] + aux[i] << " ";
    cout << endl;
    
    return 0;
}
