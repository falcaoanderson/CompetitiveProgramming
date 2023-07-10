// 10/07/23 //
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

int indegree[MAXN], status[MAXN];
vector<int> graph[MAXN], resp;
bool cycle=0;

void dfs(int u){
    status[u]=1;

    for(int v: graph[u]){
        if(status[v]==1){ // possui um ciclo
            cycle = 1;
            return;
        } 

        if(status[v]==0) dfs(v);
    }

    status[u] = 2;  
    resp.PB(u); 
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        graph[a].PB(b);
        indegree[b]++;
    }

    for(int i=1; i<=n; i++){
        if(indegree[i]==0){
            dfs(i);
        }
    }

    if(cycle || (int)resp.size()!=n){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i=(int)resp.size()-1; i>=0; i--){
        cout << resp[i] << " ";
    }
    cout << endl;

    return 0;  
}
