// 21/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;

int n, q, qnt[MAXN], pos[MAXN], ii=0;
ll bit[MAXN], val[MAXN], tree[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int pa){
    tree[++ii] = val[u];
    pos[u] = ii;

    qnt[u]=1;
    for(int v: adj[u]){
        if(v==pa) continue;

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
   
    dfs(1, 0); 
    for(int i=1; i<=n; i++) update(i, tree[i]);

    while(q--){
        int op;
        cin >> op;

        if(op==1){
            int no; ll new_val;
            cin >> no >> new_val;

            update(pos[no], new_val-val[no]);
            val[no] = new_val;
        }
        else{
            int no;
            cin >> no;

            cout << query(pos[no]+qnt[no]-1) - query(pos[no]-1)  << endl;
        }
    }

    return 0;
}
