/*
24/04/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

double memo[MAXN][5];
int n;
string s;
vector<int> adj[MAXN][5];

double dp(int u, int op, int p){
    if(memo[u][op] != -1.0) return memo[u][op];
    
    if(s[u]=='1'){
        memo[u][op] = 0;
        for(int v: adj[u][0]){
            if(v == p) continue;
            memo[u][op] += dp(v, 0, u);
        }   
        for(int v: adj[u][1]){
            if(v == p) continue;
            memo[u][op] += dp(v, 0, u);
        }   
        return memo[u][op];
    }

    //custo fixo
    double fixed_cost = 0;
    for(int v: adj[u][1]){
        if(v == p) continue;

        fixed_cost += dp(v, 0, u);
    }


    //custo variavel
    sort(adj[u][0].begin(), adj[u][0].end(), 
        [&p, &u](int a, int b){
            if(a == p) return true;
            if(b == p) return false;

            return dp(a, 0, u) - dp(a, 1, u) < dp(b, 0, u) - dp(b, 1, u); 
        }
    );

    double before = 0, after = 0;
    double D = SZ(adj[u][0]) + SZ(adj[u][1]), Dv = SZ(adj[u][1]), q = 0;

    for(int v: adj[u][0]){
        if(v == p) continue;
        after += dp(v, 1, u);
    }

    double var_cost = before + after + (s[u]=='1'? 0.0: D / (Dv + q + (double)op));
    
    for(int v: adj[u][0]){
        if(v == p) continue;
        q++;
        before  += dp(v, 0, u);
        after -= dp(v, 1, u);

        var_cost = min(var_cost, before + after + (s[u]=='1'? 0.0: D / (Dv + q + (double)op)));
    }

    // cout << u << " " << op << ": " << fixed_cost + var_cost << endl;
    return memo[u][op] = fixed_cost + var_cost;
}

void solve(){
    cin >> n >> s;

    s = ' ' + s; 
    for(int i=1; i<=n; i++){
        memo[i][0] = memo[i][1] = -1.0;
        adj[i][0].clear(); adj[i][1].clear();
    }
    
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a][s[b]=='1'].PB(b);
        adj[b][s[a]=='1'].PB(a);
    }

    int u = 0;
    for(int i=1; i<=n && u == 0; i++){
        if(s[i] == '1') u = i;
    }
    cout << dp(u, 0, -1) << endl;
}

int main(){
    fast_io;

    cout.setf(ios_base::fixed);
    cout.precision(12);

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
