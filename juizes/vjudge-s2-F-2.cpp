// 10/06/23 // dfs // O(n+m)
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

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = 2e5+5;

int tempo[MAXN], peso[MAXN];
vector<pii> graph[MAXN];

void dfs(int u, int last){
    for(pii edge: graph[u]){
        int v = edge.ff;
        int t = edge.ss;

        if(v==last) continue;
        
        peso[v] = t;
        tempo[v] = tempo[u] + (int)(peso[v]<peso[u]);

        dfs(v, u);
    }
}

int main(){
    fast_io;

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        for(int i=1; i<=n; i++){
            graph[i].clear();
        }

        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;

            graph[u].EB(v, i);
            graph[v].EB(u, i);
        }

        tempo[1] = 0;
        peso[1] = MAXN;

        dfs(1, 0);

        int resp = 0;

        for(int i=1; i<=n; i++){
            resp = max(resp, tempo[i]);
        }

        cout << resp << endl;
    }

    return 0;
}