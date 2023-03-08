// 05/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2510;

int n, m;
bool vis1[MAXN], visn[MAXN];
vector<int> adj[MAXN], rev_adj[MAXN];

void dfs (int u){
    vis1[u] = 1;

    for(int v: adj[u])
        if(!vis1[v]) dfs(v);
}
void rev_dfs (int u){
    visn[u] = 1;

    for(int v: rev_adj[u])
        if(!visn[v]) rev_dfs(v);
}

int main(){
    fast_io;
    
    cin >> n >> m;
    
    vector<tuple<int, int, ll>> edges;
    vector<ll> dist(n+1, -INF);

    for(int i=0; i<m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        
        adj[a].pb(b);
        rev_adj[b].pb(a);

        edges.pb(make_tuple(a, b, c));
    }
    
    dfs(1);
    rev_dfs(n);
    
    bool flag = 0;
    dist[1] = 0;

    for(int i=0; i<n; i++){
        bool alterou = 0;
        for(auto e: edges){
            int a, b; ll c;
            tie(a, b, c) = e;

            if(dist[b]<dist[a]+c){
                dist[b] = dist[a]+c;
                alterou = 1;

                if(i==n-1 && vis1[b]&&visn[b] ) flag = 1;
            }
        }

        if(!alterou) break;
    }

    if(flag) 
        cout << -1 << endl;
    else 
        cout << dist[n] << endl;
    
    return 0;
}
