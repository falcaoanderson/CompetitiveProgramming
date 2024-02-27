/*
14/02/24 
Problem: Road Improvement
Complexity: O(n+m)
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

int delta;
vector<pii> adj[MAXN];
vector<int> color[MAXN];

void dfs(int u, int p, int last_c){
    int c=0;
    for(pii edge: adj[u]){
        int v = edge.FF, id=edge.SS;

        if(v==p) continue;

        c++;
        if(c==last_c) c++;

        color[c].PB(id);

        dfs(v, u, c);
    }
}

int main(){
    fast_io;
    
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].EB(b, i);
        adj[b].EB(a, i);
    }

    delta = 0;
    for(int i=1; i<=n; i++) delta = max(delta, sz(adj[i]));

    dfs(1, 0, 0);

    cout << delta << endl;
    for(int i=1; i<=delta; i++){
        cout << sz(color[i]) << " ";
        for(int x: color[i]) cout << x << " ";

        cout << endl;
    }

    return 0;
}
