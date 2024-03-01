/*
01/03/24 
Problem: Codeforces Round 141 (Div. 2) - E. The Road to Berland is Paved With Good Intentions
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
const int MAXN = (1e2) + 5;
const int MOD  = (1e9) + 7;

bool possible=1, visited[MAXN], on[MAXN];
vector<pii> adj[MAXN];

void dfs(int u){
    visited[u] = 1;

    for(pii e: adj[u]){
        if(!possible) return;

        int v  = e.FF;
        int op = e.SS;

        if(visited[v]){
            possible = op ^ on[u] ^ on[v];
            continue; 
        }

        if(op^on[u]){
            on[v] = 0;
        }
        else{
            on[v] = 1;
        }

        dfs(v);
    }
    
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        adj[a].EB(b, c);
        adj[b].EB(a, c);
    }

    int cnt = 0;
    for(int u=1; u<=n && possible; u++){
        if(!visited[u]){
            dfs(u);
        }

        cnt += on[u];
    }

    if(possible){
        cout << cnt << endl;
        for(int i=1; i<=n; i++) if(on[i]) cout << i << " ";
        cout << endl;
    }
    else{
        cout << "Impossible" << endl;
    }

    

    return 0;
}