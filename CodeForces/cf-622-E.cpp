/*
08/08/24 
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

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (5e5) + 5;
const int MOD  = (1e9) + 7;

int n;
int lvl[MAXN];
vector<int> adj[MAXN];
vector<pii> depth;  

void dfs(int u, int last){
    for(int v: adj[u]){
        if(v==last) continue;

        lvl[v] = lvl[u]+1;

        if(adj[v].size()==1){
            depth.EB(lvl[v], v);
        }
        else{
            dfs(v, u);
        }
    }
}

int main(){
    fast_io;

    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }

    int resp=0;

    for(int u: adj[1]){
        depth.clear();
        dfs(u, 1);

        sort(depth.begin(), depth.end());

        int tt=0;
        for(pii p: depth){
            tt = max(tt+1, p.FF);
        }

        resp = max(resp, tt+1);
    }

    cout << resp << endl;

    return 0;
}
