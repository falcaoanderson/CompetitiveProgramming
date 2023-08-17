// 14/07/23 //
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
 
const int MAXN = (2e5) + 5;
 
vector<int> graph[MAXN];
int memo[MAXN][5];
 
int dfs(int u, int last, bool flag){
    if(memo[u][flag]!=-1) return memo[u][flag];
 
    int aux=0;
    for(int v: graph[u]){
        if(v==last) continue;
 
        aux += dfs(v, u, 0);
    }
    memo[u][flag] = aux;
 
    if(flag==1) return memo[u][flag];
 
    for(int v: graph[u]){
        if(v==last) continue;
 
        memo[u][flag] = max(memo[u][flag], aux - memo[v][0] + dfs(v, u, 1) + 1);
    }
 
    return memo[u][flag];
}
 
int main(){
    fast_io;
 
    int n;
    cin >> n;
 
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
 
        graph[a].PB(b);
        graph[b].PB(a);
    }
 
    memset(memo, -1, sizeof(memo));
    
    cout << dfs(1, 0, 0) << endl;
    
    return 0;
}