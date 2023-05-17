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
int color[MAXN];
vector<int> graph[MAXN];
 
bool dfs(int u){

    for(int v: graph[u]){
        if(color[v] == color[u]){
            return false;
        }
        else if(color[v]==0){
            color[v] = (color[u]==1? 2: 1);

            if(!dfs(v)) return false;
        }
    }

    return true;
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
    
    bool flag = true;

    for(int i=1; i<=n && flag; i++){
        if(color[i]==0){
            color[i] = 1;

            flag = dfs(i);
        }
    }

    if(!flag){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(int i=1; i<=n; i++) cout << color[i] << " ";
        cout << endl;
    }
    
    return 0;
}