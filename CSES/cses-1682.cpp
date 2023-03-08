// 11/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m; 
vector<int> adj[MAXN], rev_adj[MAXN];
vector<int> seq;
bool visitado[MAXN];

void pre_dfs(int u){
    visitado[u] = 1;
    
    for(int v: adj[u])
        if(!visitado[v]) pre_dfs(v);
    
    seq.pb(u);    
}

void dfs(int u){
    visitado[u] = 1;
    
    for(int v: rev_adj[u])
        if(!visitado[v]) dfs(v);
}

int main(){
    fast_io;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        rev_adj[b].pb(a);
    }

    for(int i=1; i<=n; i++)
        if(!visitado[i]) pre_dfs(i);
    
    memset(visitado, 0, sizeof(visitado));

    dfs(seq[n-1]);

    int u = 0;

    for(int i=1; i<=n; i++){
        if(!visitado[i]){
            u = i;
            break;
        }
    }
    
    if(u==0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
        cout << u << " " << seq[n-1] << endl;
    }

    return 0;
}
