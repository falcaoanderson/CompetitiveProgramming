// 21/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define ll long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;

int n, q, level[MAXN], first[MAXN], logg[3*MAXN];
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

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=2; i<=n; i++){
        int a;
        cin >> a;

        adj[i].pb(a);
        adj[a].pb(i);
    }

    dfs(1, 0);
    
    for(int i=1; i<=sz; i++){
        table[i][0] = tree[i];
    }
        
    for(int j=1; j<22; j++)
        for(int i=1; i<=sz; i++){
            if(i+(1<<j)-1>sz) break;

            //table[i][j] = min(table[i][j-1], table[i+1<<(j-1)][j-1]));
            if(level[table[i][j-1]] < level[table[i+(1<<(j-1))][j-1]])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i+(1<<(j-1))][j-1];
        }

   for(int i=2; i<=sz; i++) logg[i] = logg[i/2] + 1;

    while(q--){
        int a, b;
        cin >> a >> b;

        a = first[a];
        b = first[b];
        if(a>b) swap(a, b);

        int x = logg[b-a+1];

        if(level[table[a][x]] < level[table[b-(1<<x)+1][x]])
            cout << table[a][x] << endl;
        else 
            cout << table[b-(1<<x)+1][x] << endl;
    }

    return 0;
}
