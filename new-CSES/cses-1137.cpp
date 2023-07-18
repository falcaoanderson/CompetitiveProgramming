// 18/07/23 //
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
ll value[MAXN], bit[MAXN];
vector<int> adj[MAXN];

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

    for(int v: adj[u]){
        if(v==last) continue;

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

    for(int i=1; i<=n; i++) update(tree[i], value[i]);

    while(q--){
        int op, s;
        cin >> op >> s;

        if(op==1){ //update
            ll x;
            cin >> x;

            update(tree[s], x-value[s]);
            value[s] = x;
        }   
        else{ // query
            cout << query(tree[s]+sz[s]-1) - query(tree[s]-1) << endl;
        }
    }

    return 0;
}
