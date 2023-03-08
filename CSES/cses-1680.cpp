// 09/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, ll> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m, grau[MAXN], memo[MAXN], ant[MAXN];
vector<int> adj[MAXN], rev_adj[MAXN];

int main(){
    fast_io;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        rev_adj[b].pb(a);
        grau[b]++;
    }

    queue<int> fila;

    for(int i=1; i<=n; i++){
        memo[i] = -INF;
        if(grau[i]==0) fila.push(i);
    }
    memo[1] = 1;

    while(!fila.empty()){
        int u = fila.front(); fila.pop();

        for(int v: rev_adj[u])
            if(memo[v]+1>memo[u]){
                memo[u] = memo[v]+1;
                ant[u] = v;
            }
        
        if(u==n) break;

        for(int v: adj[u]){
            grau[v]--;
            if(grau[v]==0) fila.push(v);
        }
    }  

    if(memo[n]<=0) cout << "IMPOSSIBLE" << endl;  
    else{
        cout << memo[n] << endl;

        vector<int> path;
        int u = n;
        while(u!=1){
            path.pb(u);
            u = ant[u];
        }
        path.pb(u);

        reverse(path.begin(), path.end());
        for(int i: path) cout << i << " ";
        cout << endl;
    }

    return 0;
}
