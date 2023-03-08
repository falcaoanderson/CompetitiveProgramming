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
int dist[MAXN]; // dist[i] == maior distancia de i ate alguem de sua subarvore
int diameter=0;

void dfs(int u, int pa){
    int distf1=0, distf2=0;
    dist[u] = 0;

    for(int v: adj[u]){
        if(v==pa) continue;

        dfs(v, u);

        dist[u] = max(dist[u], dist[v]+1);

        if(dist[v]+1>distf1){     // calcula o maior caminho onde 'u' eh o vertice mais alto do caminho
            distf2 = distf1;
            distf1 = dist[v]+1;
        }
        else if(dist[v]+1>distf2){
            distf2 = dist[v]+1;
        }
    }

    diameter = max(diameter, distf1+distf2);
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

    dfs(1, 0);

    cout << diameter << endl;

    return 0;
}
