// 25/11/20 // xx:xx PM //
// solve aprox O(n^2)

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back

const int MAXN = (1e5) + 10;

int n, m, resp[MAXN], sufix[MAXN];
vector<int> adj[MAXN];

int main(){
    fast_io;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b); adj[b].pb(a);
    }

    for(int i=1; i<=n; i++) sort(adj[i].begin(), adj[i].end());
    for(int i=1; i<=n; i++) resp[i] = 1;

    for(int i=n; i>=1; i--){

        for(int j=0; j<(int)adj[i].size(); j++){
            int melhor=0;

            for(int k=j+1; k<(int)adj[i].size(); k++) melhor = max(melhor, resp[adj[i][k]]);

            resp[adj[i][j]] = max(resp[adj[i][j]], 2+melhor);
        }
    }    

    for(int i=1; i<=n; i++) cout << resp[i] << " ";
    cout << endl;

    return 0;
}
