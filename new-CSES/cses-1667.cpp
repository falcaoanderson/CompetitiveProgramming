// 16/05/23 // bfs // O(n+m)
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
int path[MAXN];
vector<int> graph[MAXN];

void bfs(int u){
    queue<int> process;
    process.push(u);

    path[u] = -1;

    while(!process.empty() && path[n]==0){
        u = process.front();
        process.pop();

        for(int v: graph[u]){
            if(path[v]==0){
                path[v] = u;

                process.push(v); 
            }
        }
    }
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

    bfs(1);

    if(path[n]==0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> resp;
    int u = n;
    resp.PB(u);
    while(u!=1){
        u = path[u];
        resp.PB(u);
    }

    cout << resp.size() << endl;
    for(int i=(int)resp.size()-1; i>=0; i--){
        cout << resp[i] << " ";
    }
    cout << endl;

    return 0;
}