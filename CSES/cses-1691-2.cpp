// 11/11/20 // xx:xx PM //

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
const int MAXN = (1e5) + 10;
const int MAXM = (2e5) + 10;

int n, m, grau[MAXN];
vector<int> path;
vector<pii> adj[MAXN];
bool visited[MAXM];

void eulerian(){
    stack<int> pilha;
    pilha.push(1);

    while(!pilha.empty()){
        int u = pilha.top();
    
        while(!adj[u].empty() && visited[adj[u].back().second]){
            adj[u].pop_back();
        }

        if(adj[u].empty()){
            path.pb(u);
            pilha.pop();
        }
        else{
            pii e = adj[u].back();
            
            adj[u].pop_back();
            visited[e.second] = 1;

            pilha.push(e.first);
        }
    }
}

int main(){
    fast_io;
    
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb({b, i});
        adj[b].pb({a, i});

        grau[a]++; grau[b]++;
    }

    for(int i=1; i<=n; i++)
        if(grau[i]&1){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    
    
    eulerian();

    if((int)path.size()!=m+1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(int u: path)
            cout << u << " ";
        cout << endl;
    }
    
    return 0;
}
