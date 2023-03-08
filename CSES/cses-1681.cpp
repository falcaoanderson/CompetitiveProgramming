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

const int MOD  = (1e9)+7;
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

    for(int i=1; i<=n; i++) if(grau[i]==0) fila.push(i);

    memo[1] = 1;

    while(!fila.empty()){
        int u = fila.front(); fila.pop();


        for(int v: rev_adj[u]) memo[u] = (memo[u]+memo[v])%MOD;
        
        if(u==n) break;

        for(int v: adj[u]){
            grau[v]--;
            if(grau[v]==0) fila.push(v);
        }
    }  

    cout << memo[n] << endl;
    

    return 0;
}
