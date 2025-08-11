/*
08/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int n, m;
int parent[2*MAXN], lvl[2*MAXN];
int grid[MAXN][MAXN];
vector<int> adj[2*MAXN];
int val[2*MAXN], indegree[2*MAXN];
bool visited[2*MAXN];

int find(int u){
    if(parent[u] == u) return u;

    return parent[u] = find(parent[u]);
}
void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v){
        return;
    }
    
    if(lvl[u]<=lvl[v]){
        parent[u] = v;

        if(lvl[u]==lvl[v]){
            lvl[v]++;
        }
    }
    else{
        parent[v] = u;
    }
}

int main(){
    fast_io;

    cin >> n >> m;
    
    for(int i=0; i<(n+m); i++){
        parent[i] = i;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;

            if(c=='>'){
                grid[i][j]=1;
            }
            else if(c=='<'){
                grid[i][j]=-1;
            }
            else{
                grid[i][j]=0;

                join(i, n+j);
            }
        }
    }

    bool resp = 1;

    for(int i=0; i<n && resp; i++){
        int u = find(i);
        for(int j=0; j<m; j++){
            int v = find(n+j);

            if(u==v && grid[i][j]!=0){
                resp = 0;
                break;
            }
            if(grid[i][j]==1){
                adj[u].PB(v);
                indegree[v]++;
            }
            else if(grid[i][j]==-1){
                adj[v].PB(u);
                indegree[u]++;
            }
        }
    }

    if(!resp){
        cout << "No" << endl;
        return 0;
    }

    queue<int> fila;
    for(int i=0; i<n+m; i++){
        int u = find(i);
        if(u==i && indegree[u]==0){
            val[u] = 1e6;
            fila.push(u);
        }
    }

    resp = !fila.empty();
    int minval = 1e6;
    while(resp && !fila.empty()){
        int u = fila.front();
        fila.pop();

        if(visited[u]) continue;
        visited[u] = 1;

        for(int v: adj[u]){
            indegree[v]--;

            if(val[v]!=0 && val[u] <= val[v]){
                resp = 0;
                break;
            }
            if(indegree[v]==0 && val[v]==0){
                val[v] = val[u]-1;
                minval = min(minval, val[v]);
                fila.push(v);
            }
        }

    }

    for(int i=0; i<n+m && resp; i++){
        resp = (val[i]!=0 || i!=find(i));
    }

    if(!resp){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;

        for(int i=0; i<n; i++) cout << val[find(i)]-minval+1 << " ";
        cout << endl;
        for(int i=n; i<n+m; i++) cout << val[find(i)]-minval+1 << " ";
        cout << endl;
    }

    return 0;
}

