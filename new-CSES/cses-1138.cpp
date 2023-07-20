// 20/07/23 //
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
 
int n, sz[MAXN], tree[MAXN], i_tree=0;
ll value[MAXN], dist[MAXN];
vector<int> adj[MAXN];

ll bit[MAXN]; 
void update(int pos, ll val){
    while(pos<=n){
        bit[pos] += val;
        pos += (pos&-pos);
    }
}
ll query(int pos){
    ll sum=0LL;
    while(pos>0){
        sum += bit[pos];
        pos -= (pos&-pos);
    }
    return sum;
}
 
void dfs(int u, int last){
    tree[u] = ++i_tree;
    sz[u] = 1;
    dist[u] += value[u];

    for(int v: adj[u]){
        if(v==last) continue;

        dist[v] = dist[u];  

        dfs(v, u);
 
        sz[u] += sz[v];
    }
}

int main(){
    fast_io;
 
    int q;
    cin >> n >> q;
 
    for(int i=1; i<=n; i++) cin >> value[i];
    
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;
 
        adj[a].PB(b);
        adj[b].PB(a);
    }
 
    dfs(1, 0);
    
    vector<ll> aux(n+1);
    for(int i=1; i<=n; i++) aux[ tree[i] ] = dist[i];
    for(int i=n; i>=1; i--) aux[i] -= aux[i-1];
    
    for(int i=1; i<=n; i++) update(i, aux[i]);
 
    while(q--){
        int op, s;
        cin >> op >> s;
 
        if(op==1){ //update
            ll x;
            cin >> x;
 
            update(tree[s], x-value[s]);
            update(tree[s]+sz[s], value[s]-x);

            value[s] = x;
        }   
        else{ // query
            cout << query(tree[s]) << endl;
        }
    }
 
    return 0;
}