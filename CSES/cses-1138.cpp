// 21/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;

int n, q, qnt[MAXN], pos[MAXN], ii=0;
ll val[MAXN], tree[MAXN], dist[MAXN], bit[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int pa){
    tree[++ii] = dist[u];  
    pos[u]  = ii;

    qnt[u] = 1;
    for(int v: adj[u]){
        if(v==pa) continue;

        dist[v] = dist[u] + val[v];
        
        dfs(v, u);

        qnt[u] += qnt[v];
    }
}

void update(int i, ll sum){
    while(i<=n){
        bit[i] += sum;
        i += (i&-i);
    }
}

ll query(int i){
    ll sum = 0LL;
    while(i>0){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
}

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> val[i];
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    dist[1] = val[1];
    dfs(1, 0);

    for(int i=1; i<=n; i++){
        update(i, tree[i]-tree[i-1]);
    }

    while(q--){
        int op;
        cin >> op;

        if(op==1){
            int u; ll new_val;
            cin >> u >> new_val;

            update(pos[u], new_val-val[u]);
            update(pos[u]+qnt[u], val[u]-new_val);

            val[u] = new_val;
        }
        else{
            int u;
            cin >> u;

            cout << query(pos[u]) << endl;
        }
    }

    return 0;
}
