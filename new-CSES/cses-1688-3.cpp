/*
Date: 21/11/23 
Problem: LCA offline
Complexity: O((n+q)*alpha(n+q, n))
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

typedef pair<int, int> pii;

const int MAXN = (2e5) + 5;

int n;
vector<int> adj[MAXN];
vector<pii> query[MAXN];
int pai[MAXN], resp_query[MAXN];

int find(int u){
    if(pai[u]==u) return u;

    return pai[u] = find(pai[u]);
}

void dfs(int u){
    pai[u] = u;

    for(int v: adj[u]){
        if(pai[v]!=0) continue;

        dfs(v);
        
        pai[find(v)] = find(u);
    }

    for(pii w_id: query[u]){
        int w  = w_id.FF;
        int id = w_id.SS;

        if(pai[w]!=0){
            resp_query[id] = pai[find(w)];
        }
    }
}

int main(){
    fast_io;

    int q;
    cin >> n >> q;

    for(int b=2; b<=n; b++){
        int a;
        cin >> a;

        adj[a].PB(b);
    }

    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;

        query[a].EB(b, i);
        query[b].EB(a, i);
    }

    dfs(1);

    for(int i=0; i<q; i++){
        cout << resp_query[i] << endl;
    }

    return 0;
}
