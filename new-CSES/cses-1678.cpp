// 13/07/23 //
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
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

vector<int> graph[MAXN];
int status[MAXN], last[MAXN];

int dfs(int u){
    status[u] = 1;

    int flag=0;
    for(int v: graph[u]){
        if(status[v]==0){
            last[v] = u;
            flag = dfs(v);
        }
        else if(status[v]==1){
            last[v] = u;
            flag=u; // achei um ciclo
        }

        if(flag!=0) break;
    }

    status[u] = 2;
    return flag;
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;

        graph[a].PB(b);
    }

    int ini=0;

    for(int u=1; u<=n; u++){
        if(status[u]==0){
            ini = dfs(u);
            if(ini!=0) break;
        }
    }

    if(ini==0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        stack<int> path;

        path.push(ini);
        int u = last[ini];
        while(u != ini){
            path.push(u);
            u = last[u];
        }
        path.push(u);

        cout << path.size() << endl;
        while(!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }

    return 0;
}