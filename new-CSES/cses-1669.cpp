// 18/05/23 // dfs // O(n + m)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
 
using namespace std;
 
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define ll long long
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int MAXN = (1e5) + 5;
 
int n, m;
bool visited[MAXN];
int path[MAXN];
vector<int> graph[MAXN];
 
int dfs(int u){
    
    visited[u] = 1;

    for(int v: graph[u]){
        if(visited[v] && path[v]!=u){
            path[u] = v;
            return v;
        }
        if(!visited[v]){
            path[u] = v;
            int aux = dfs(v); 

            if(aux!=-1) return aux;
        }
    }

    return -1;
}
 
int main(){
    fast_io;
 
    cin >> n >> m;
 
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
 
        graph[a].PB(b);
        graph[b].PB(a);
    }
    
    int resp = -1;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            resp = dfs(i);

            if(resp!=-1) break; 
        }
    }

    if(resp==-1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        int u = resp;

        vector<int> aux;
        while(path[u]!=resp){
            aux.PB(u);
            u = path[u];
        }
        aux.PB(u);
        aux.PB(resp);

        cout << aux.size() << endl;
        for(int i: aux) cout << i << " ";
        cout << endl;

    }

    return 0;
}