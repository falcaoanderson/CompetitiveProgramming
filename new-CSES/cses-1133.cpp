// 14/07/23 //
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

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (2e5) + 5;

ll n, qnt[MAXN], dist_down[MAXN], dist_up[MAXN];
vector<int> adj[MAXN];

void dfs1(int u, int last){
    qnt[u] = 1LL;
    
    for(int v: adj[u]){
        if(v==last) continue;

        dfs1(v, u);

        qnt[u] += qnt[v];
        dist_down[u] += (dist_down[v] + qnt[v]);
    }   
}

void dfs2(int u, int last){ 
    if(u!=1) dist_up[u] = dist_up[last] + (dist_down[last] - dist_down[u] - qnt[u]) + (n-qnt[u]);

    for(int v: adj[u]){
        if(v==last) continue;

        dfs2(v, u);
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

    dfs1(1, 0);
    dfs2(1, 0);

    for(int i=1; i<=n; i++)
        cout << (dist_down[i] + dist_up[i]) << " "; 
    cout << endl;

    return 0;
}
