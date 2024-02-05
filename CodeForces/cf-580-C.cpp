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

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

bool cat[MAXN];
vector<int> adj[MAXN];
int crr[MAXN], max_crr[MAXN];

void dfs(int u, int last){
    if(cat[u]){
        crr[u] = crr[last] + 1;
    }

    max_crr[u] = max(crr[u], max_crr[last]);

    for(int v: adj[u]){
        if(v != last) dfs(v, u);
    }
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> cat[i];

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }

    dfs(1, 0);

    int resp = 0;

    for(int i=2; i<=n; i++){
        if(adj[i].size()==1 && max_crr[i]<=m) resp++;
    }

    cout << resp << endl;

    return 0;
}
