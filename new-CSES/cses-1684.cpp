/*
27/02/24 
Problem: CSES Problem Set - Giant Pizza
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

int qnt_color, color[MAXN];
vector<int> adj[MAXN], adj_t[MAXN];
stack<int> dfs_order;

void dfs1(int u){
    color[u] = 1;

    for(int v: adj[u]){
        if(color[v]==0) dfs1(v);
    }

    dfs_order.push(u);
}

void dfs2(int u){
    for(int v: adj_t[u]){
        if(color[v]==0){
            color[v] = color[u];
            dfs2(v);
        }
    }
}

void add_edges(int a, bool neg_a, int b, bool neg_b){
    a = 2*a + neg_a;
    b = 2*b + neg_b;

    adj[a^1].PB(b);
    adj[b^1].PB(a);
    
    adj_t[b].PB(a^1);
    adj_t[a].PB(b^1);
}

int main(){
    fast_io;

    int n, m;
    cin >> m >> n;

    for(int i=0; i<m; i++){
        int a, b;
        char op_a, op_b;
        cin >> op_a >> a >> op_b >> b;
        
        add_edges(a-1, op_a=='-', b-1, op_b=='-');
    }

    for(int u=0; u<2*n; u++){
        if(color[u]==0) dfs1(u);
    }
    
    memset(color, 0, sizeof(color));
    qnt_color = 0;

    while(!dfs_order.empty()){
        int u = dfs_order.top();
        dfs_order.pop();

        if(color[u]==0){
            color[u] = (++qnt_color);
            
            dfs2(u);
        }
    }

    bool impossible = 0;
    vector<bool> resp(n);

    for(int i=0; i<n && !impossible; i++){
        int u = 2*i;

        if(color[u]==color[u^1]){
            impossible = 1;
        }
        else{
            resp[i] = (color[u]>color[u^1]);
        }
    }

    if(impossible) 
        cout << "IMPOSSIBLE" << endl;
    else{
        for(bool x: resp) cout << (x?"+":"-") << " ";
        cout << endl;
    }

    return 0;
}