/*
07/02/24 
Problem: 
Complexity:
*/

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
#include <stack>
#include <functional>
#include <cmath>

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
const int MAXK = (1e4) + 5;
const int MOD  = (1e9) + 7;

int fim, k, memo[MAXN][MAXK];
vector<pii> adj[MAXN];
vector<int> path;

int solve(int u, int dist){
    if(memo[u][dist]!=-1) return memo[u][dist]; 
    
    if(dist==0) return memo[u][dist] = (u==fim);

    for(pii edge: adj[u]){
        int v=edge.FF, c=edge.SS;

        if(dist>=c && solve(v, dist-c)){
            path.PB(u);
            return memo[u][dist] = 1;
        }
    }

    return memo[u][dist] = 0;
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m >> k;

    int ini;
    cin >> ini >> fim;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(c>k) continue;

        adj[a].EB(b, c);
        adj[b].EB(a, c);
    }

    memset(memo, -1, sizeof(memo));

    if(!solve(ini, k)){
        cout << "Impossible" << endl;
    }
    else{
        reverse(path.begin(), path.end());
        path.PB(fim);

        for(int u: path) cout << u << " ";
        cout << endl;
    }

    return 0;
}
