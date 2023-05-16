// 16/05/23 // dfs // O(n+m)
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
vector<int> graph[MAXN];

void dfs(int u){
    visited[u] = 1;

    for(int v: graph[u]){
        if(!visited[v]) dfs(v);
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

    vector<int> resp;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            resp.PB(i);
            dfs(i);
        }
    }

    cout << (int)resp.size()-1 << endl;

    for(int i=1; i<(int)resp.size(); i++){
        cout << resp[i-1] << " " << resp[i] << endl;
    }

    return 0;
}