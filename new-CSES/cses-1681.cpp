// 26/05/23 // dfs + dp on graphs // O(n+m)
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

const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int n, m;
int ways[MAXN];
vector<int> graph[MAXN];

void dfs(int u){
    ways[u] = (u!=n? 0: 1);

    for(int v: graph[u]){
        if(ways[v]==-1) dfs(v);

        ways[u] = (ways[u] + ways[v])%MOD;
    }
} 

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        graph[a].PB(b);
    }

    memset(ways, -1, sizeof(ways));
    dfs(1);

    cout << ways[1] << endl;

    return 0;
}
