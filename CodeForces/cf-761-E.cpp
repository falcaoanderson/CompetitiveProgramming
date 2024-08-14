/*
14/08/24 
Problem: 
Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 30 + 5;
const int MOD  = (1e9) + 7;

int n;
vector<int> adj[MAXN];
pll resp[MAXN];
int aux_x[] = {0, 1, 0, -1, 0, 0};
int aux_y[] = {1, 0, -1, 0, 0, 0};


void dfs(int u, int last, ll x, ll y, int last_dir, int cont){
    resp[u] = pll(x, y);

    int dir=0;
    for(int v: adj[u]){
        if(v==last) continue;

        if(dir==last_dir){
            dir=(dir+1)%4;
        }

        dfs(v, u, x+(1LL<<cont)*aux_x[dir], y+(1LL<<cont)*aux_y[dir], (dir+2)%4, cont-1);

        dir=(dir+1)%4;
    }
}   

int main(){
    fast_io;

    cin >> n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].PB(v);
        adj[v].PB(u);
    }
    
    bool possible=1;
    for(int i=1; i<=n && possible; i++){
        possible = (int)adj[i].size()<=4;
    }

    if(!possible){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        
        dfs(1, 0, 0, 0, -1, 29);
        for(int i=1; i<=n; i++){
            cout << resp[i].FF << " " << resp[i].SS << endl;
        }
    }

    return 0;
}
