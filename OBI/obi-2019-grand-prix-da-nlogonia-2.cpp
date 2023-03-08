// 24/11/20 // xx:xx PM //

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

struct plano{
    int u=0, l=0, r=0;
};

int n, m;
int v[5*MAXN], visitado[5*MAXN], ii=0;
plano qq[MAXN];
vector<int> adj[5*MAXN];

void build(int no, int i, int j){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    v[no] = ++ii;

    if(i==j){
        adj[v[no]].pb(i);
    }
    else{
        build(l, i, mid);
        build(r, mid+1, j);

        adj[v[no]].pb(v[l]);
        adj[v[no]].pb(v[r]);
    }
}

void add_plano(int no, int i, int j, int u, int a, int b){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(j<a || b<i) return;

    if(a<=i && j<=b){
        adj[u].pb(v[no]);
    }
    else{
        add_plano(l, i, mid, u, a, b);
        add_plano(r, mid+1, j, u, a, b);
    }
}

bool dfs(int u){
    visitado[u] = 1;

    for(int v: adj[u]){
        if(visitado[v]==1) return true;
        if(visitado[v]==0 && dfs(v))
            return true;
    }

    visitado[u] = 2;
    return false;
}

bool solve(int x){
    memset(visitado, 0, sizeof(visitado));
    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=1; i<=x; i++) add_plano(1, 1, n, qq[i].u, qq[i].l, qq[i].r);

    for(int i=1; i<=n; i++)
        if(visitado[i]==0 && dfs(i)) 
            return true;
    
    return false;
}

int main(){
    fast_io;

    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> qq[i].u >> qq[i].l >> qq[i].r;

    ii = n;
    build(1, 1, n);

    int l=1, r=m, mid, resp=-1;
    while(l<=r){
        mid = (l+r)/2;

        if(solve(mid)){
            resp = mid;
            r = mid-1;
        }
        else 
            l = mid+1; 
    }

    cout << resp << endl;

    return 0;
}
