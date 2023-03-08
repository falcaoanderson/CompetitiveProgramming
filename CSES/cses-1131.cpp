// 20/11/20 // xx:xx PM //

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
const int MOD  = (1e9) + 7;

int n;
vector<int> adj[MAXN];

pii dfs(int u, int p){
    
    int dist=0, no = u;

    for(int v: adj[u]){
        if(v==p) continue;

        pii temp = dfs(v, u);

        if(temp.first+1>dist){
            dist = temp.first + 1;
            no   = temp.second;
        }
    }

    return pii(dist, no);
}

int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    cout << dfs(dfs(1, 0).second, 0).first << endl;

    return 0;
}
