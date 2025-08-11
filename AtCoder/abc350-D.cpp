/*
11/08/25 

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

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

bool visited[MAXN];
vector<int> adj[MAXN];

ll aux1, aux2;
void dfs(int u){
    visited[u] = 1;
    aux1++;
    aux2+=adj[u].size();
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    fast_io;

    ll n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }

    ll resp = 0; 
    for(int u=1; u<=n; u++){
        aux1 = aux2 = 0;
        if(!visited[u]){
            dfs(u);
            resp += (aux1*(aux1-1LL))/2LL - aux2/2LL;
        }
    }

    cout << resp << endl;;

    return 0;
}
