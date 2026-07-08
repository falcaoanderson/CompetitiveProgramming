/*
03/04/26 

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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> down(n, vector<int>(m)), right(n, vector<int>(m));
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            cin >> down[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m-1; j++){
            cin >> right[i][j];
        }
    }

    vector<vector<int>> adj(n*m);
    vector<bool> blocked(n*m);
    for(int i=0; i<n-1; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            if(s[j]=='0'){
                int u = i*m + j, v = i*m + j-1;
                if(0 < j && j < m-1){  
                    adj[u].PB(v);
                    adj[v].PB(u);
                }
                else if(j == 0){
                    blocked[u] = 1;
                }
                else if(j == m-1){
                    blocked[v] = 1;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m-1; j++){
            if(s[j]=='0'){
                int u = i * m + j, v = (i-1) * m + j; 
                if(0 < i && i < n-1){ 
                    adj[u].PB(v);
                    adj[v].PB(u);
                }
                else if(i == 0){
                    blocked[u] = 1;
                }
                else if(i == n-1){
                    blocked[v] = 1;
                }
            }
        }
    }

    auto fcalc = [&down, &right](int i, int j){
        return (ll)(down[i][j] - down[i][j+1]) + (ll)(right[i][j] - right[i+1][j]);
    };

    vector<bool> visited(n*m);
    ll ans = 0;
    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            int u = i*m + j;
            
            if(visited[u]) continue;

            queue<int> fila;
            fila.push(u);
            visited[u] = 1;
            ll cost = 0;
            bool flag = 0;

            // cout << "componente: ";
            while(!fila.empty()){
                u = fila.front(); fila.pop();
                int ux = u / m, uy = u % m;
                // cout << ux << " " << uy << endl;
                
                if(blocked[u]){
                    flag = 1;
                    cost = 0;
                }
                if(!flag) cost += fcalc(ux, uy);
                
                for(int v: adj[u]){
                    if(!visited[v]){
                        visited[v] = 1;
                        fila.push(v);
                    }
                }
            }

            // cout << "Cost: " << cost << endl;
            if(cost > 0){
                ans += cost;
            }
        }
    }

    cout << ans << endl;
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
