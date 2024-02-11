/*
05/02/24 
Problem: CSES - Strongly Connected Edges
Complexity: O(n+m)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>
#include <functional>
#include <cmath>

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
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

vector<int> adj[MAXN], resp[MAXN];
int tt=0, in[MAXN], low[MAXN];
bool impossible = 0;

void dfs(int u, int p){
    in[u] = low[u] = ++tt;

    for(int v: adj[u]){
        if(v==p) continue;

        if(in[v]==0){ //filho
            dfs(v, u);

            resp[u].PB(v);

            low[u] = min(low[u], low[v]);
        
            if(low[v]>in[u]){ //ponte
                impossible = 1;
            }
        }
        else if(in[v]!=0 && in[v]<in[u]){ //back edge
            resp[u].PB(v);
            
            low[u] = min(low[u], in[v]);
        }
    }
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }

    dfs(1, 0);

    for(int i=1; i<=n && !impossible; i++) impossible = (in[i]==0);

    if(impossible){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(int u=1; u<=n; u++){
            for(int v: resp[u]){
                cout << u << " " << v << endl;
            }
        }
    }
        
    return 0;
}
