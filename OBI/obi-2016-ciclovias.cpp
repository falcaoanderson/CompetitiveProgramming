// 25/11/20 // xx:xx PM //
// solve O(n^3)

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int MAXN = (1e5) + 10;

int n, m;
vector<int> adj[MAXN];
int memo[100][100][100];

short int dfs(int u, int maior_impar, int maior_par){
    if(memo[u][maior_impar][maior_par]!=-1) return memo[u][maior_impar][maior_par];
    
    memo[u][maior_impar][maior_par] = 0;
    for(int v: adj[u]){
        if(u==maior_impar && v>maior_par)
            memo[u][maior_impar][maior_par] = max(memo[u][maior_impar][maior_par], 1 + dfs(v, maior_impar, v));
        if(u==maior_par && v>maior_impar)
            memo[u][maior_impar][maior_par] = max(memo[u][maior_impar][maior_par], 1 + dfs(v, v, maior_par));
    }

    return memo[u][maior_impar][maior_par];
}

int main(){
    fast_io;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b); adj[b].pb(a);
    }

    memset(memo, -1, sizeof(memo));
 
    for(int i=1; i<=n; i++)
        cout << dfs(i, i, 0) + 1<< " ";
    cout << endl;

    return 0;
}
