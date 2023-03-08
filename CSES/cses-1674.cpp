// 19/11/20 // xx:xx PM //

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

int n, qnt[MAXN];
vector<int> adj[MAXN];

int dfs(int u, int ant){
    for(int v: adj[u])
        if(v!=ant)
            qnt[u] += dfs(v, u) + 1;

    return qnt[u];
}

int main(){
    fast_io;

    cin >> n;
    for(int i=2; i<=n; i++){
        int u;
        cin >> u;

        adj[u].pb(i);
    }
    
    dfs(1,0);

    for(int i=1; i<=n; i++) cout << qnt[i] << " ";
    cout << endl;

    return 0;
}
