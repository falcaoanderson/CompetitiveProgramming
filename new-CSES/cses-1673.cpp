// 23/05/23 // belmann-ford + dfs // O(n*m)
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

const int MAXN = 2500+5;
const ll INF  = 0x3f3f3f3f3f3f3f3f;

int n, m;
vector<int> graph[MAXN], igraph[MAXN];
bool visited1[MAXN], visited2[MAXN];

void dfs1(int u){
    visited1[u] = 1;

    for(int v: graph[u]){
        if(!visited1[v]) dfs1(v);
    }
}
void dfs2(int u){
    visited2[u] = 1;

    for(int iv: igraph[u]){
        if(!visited2[iv]) dfs2(iv);
    }
}

int main(){
    fast_io;
    
    cin >> n >> m;

    vector<tiii> edge;

    for(int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].PB(b);
        igraph[b].PB(a);
        edge.EB(a, b, w);
    }   
    
    visited1[1] = 1;
    dfs1(1);

    visited2[n] = 1;
    dfs2(n);

    vector<ll> dist(n+1, -INF);
    dist[1] = 0LL;
    bool flag = true, cycle=false;

    for(int i=1; i<=2*n && flag && !cycle; i++){
        flag = false;

        for(tiii e: edge){
            int a, b, w;
            tie(a, b, w) = e;

            if(dist[b]< dist[a] + w){
                dist[b] = dist[a] + (ll)w;
                flag = true;

                if(i>=n && visited1[b] && visited2[b]){
                    cycle=true;
                }
            }
        }
    }

    if(!cycle){
        cout << dist[n] << endl;
    }
    else{
        cout << -1 << endl;
    }
    
    return 0;
}
