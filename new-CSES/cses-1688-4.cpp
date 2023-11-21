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
int pai[MAXN], ancestor[MAXN], rank_set[MAXN], resp_query[MAXN];

void make_set(int u){
    pai[u] = u;
    rank_set[u] = 1;
}

int find(int u){
    if(pai[u]==u) return u;

    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v); 

    if(u==v) return;

    if(rank_set[u]<rank_set[v]){
        pai[u] = v;
    }
    else if(rank_set[u]>rank_set[v]){
        pai[v] = u;
    }
    else{
        pai[u] = v;
        rank_set[v]++;
    }
}

void dfs(int u){
    make_set(u);
    ancestor[u] = u;

    for(int v: adj[u]){
        if(pai[v]!=0) continue;

        dfs(v);
        
        join(u, v);
        ancestor[find(u)] = u;
    }

    for(pii v_id: query[u]){
        int v  = v_id.FF;
        int id = v_id.SS;

        if(pai[v]!=0){
            resp_query[id] = ancestor[find(v)];
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
