// 20/09/23 //
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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

vector<int> adj[MAXN], iadj[MAXN];
bool visited[MAXN];
int qnt[MAXN];

void dfs(int u, int not_u){
    visited[u] = 1;
    qnt[u]++;

    for(int v: iadj[u]){
        if(!visited[v] && v!=not_u){
            dfs(v, not_u);
        }
    }
}

int main(){
    fast_io;

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;

        adj[i].PB(a);
        adj[i].PB(b);
        iadj[a].PB(i);
        iadj[b].PB(i);
    }
    
    for(int i=1; i<=n; i++){
        memset(qnt, 0, sizeof(qnt));

        memset(visited, 0, sizeof(visited));
        dfs(i, i);

        memset(visited, 0, sizeof(visited));
        dfs(adj[i][0], i);

        memset(visited, 0, sizeof(visited));
        dfs(adj[i][1], i);

        bool resp = 1;
        for(int j=1; j<=n; j++){
            if(j!=i && qnt[j]==3){
                resp = 0;
                break;
            }
        }

        cout << (resp? "N": "Y");
    }
    cout << endl;
    
    return 0;
}
