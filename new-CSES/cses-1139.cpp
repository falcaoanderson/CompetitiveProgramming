// 20/07/23 //
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

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int n, value[MAXN], resp[MAXN];
vector<int> adj[MAXN];

set<int> dfs(int u, int last){
    set<int> u_set = {value[u]};

    for(int v: adj[u]){
        if(v==last) continue;

        set<int> v_set = dfs(v, u);

        if(v_set.size()>u_set.size()){
            swap(v_set, u_set);
        }

        u_set.insert(v_set.begin(), v_set.end());
    }

    resp[u] = u_set.size();

    return u_set;
}

int main(){
    fast_io;

    cin >> n;
    
    for(int i=1; i<=n; i++) cin >> value[i];

    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;
 
        adj[a].PB(b);
        adj[b].PB(a);
    }

    dfs(1, 0);

    for(int i=1; i<=n; i++) cout << resp[i] << " "; 
    cout << endl;

    return 0;
}
