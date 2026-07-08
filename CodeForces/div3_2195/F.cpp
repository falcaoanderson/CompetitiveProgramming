/*
20/02/26 

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

bool diff_everywhere(int i, int j, vector<vector<ll>> &pol){
    ll a = pol[i][0] - pol[j][0], b = pol[i][1] - pol[j][1], c = pol[i][2] - pol[j][2];

    if(a == 0){ // first degree
        return (b == 0 && c != 0);
    }

    return (b * b - 4LL * a * c) < 0LL; 
}

void dfs(int u, vector<vector<int>> &adj, vector<int>& memo){
    memo[u] = 1;

    for(int v: adj[u]){
        if(memo[v] == -1) dfs(v, adj, memo);
        
        memo[u] = max(memo[u], memo[v] + 1);
    }
}
void dfs2(int u, vector<vector<int>> &adj, vector<int>& memo, vector<int>& aux){
    memo[u] = 1 + aux[u];

    for(int v: adj[u]){
        if(memo[v] == -1) dfs2(v, adj, memo, aux);
        
        memo[u] = max(memo[u], memo[v] + 1);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<ll>> pol(n, vector<ll>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> pol[i][j];
        }
    } 

    vector<vector<int>> adj(n), radj(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(pol[i][0] * pol[j][0] > 0 && diff_everywhere(i, j, pol)){
                if(pol[i][0] > 0 && pol[i][2] > pol[j][2]){
                    adj[j].PB(i);
                    radj[i].PB(j);
                }
                else if(pol[i][0] < 0 && pol[i][2] < pol[j][2]){
                    adj[j].PB(i);
                    radj[i].PB(j);
                }
            }
        }
    }

    vector<int> path_in(n, -1), path_out(n, -1), out_aux(n, 0);
    for(int i=0; i<n; i++){
        if(path_in[i]==-1) dfs(i, adj, path_in);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(pol[i][0] * pol[j][0] < 0 && diff_everywhere(i, j, pol)){
                out_aux[i] = max(out_aux[i], path_in[j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(path_out[i]==-1) dfs2(i, radj, path_out, out_aux);

        cout << path_in[i] + path_out[i] - 1 << " ";
    }
    cout << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
