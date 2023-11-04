/*
04/11/23 
Problem: CSES - Teleporters Path
Complexity: O(M)
*/

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
 
const int MAXN = (1e5) + 5;
 
int n, indegree[MAXN], outdegree[MAXN];
queue<int> adj[MAXN];
stack<int> path;
 
void dfs(int u){    
    while(!adj[u].empty()){
        int v = adj[u].front();
        adj[u].pop();

        dfs(v);
    }
 
    path.push(u);
}
 
int main(){
    fast_io;
 
    int m;
    cin >> n >> m;
 
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
 
        adj[a].push(b);
 
        outdegree[a]++;
        indegree[b]++;
    }
    
    bool possible = 1;
    int start_path = 0, end_path=0;

    for(int i=1; i<=n && possible; i++){
        if(outdegree[i]-indegree[i]==1){
            if(start_path==0){
                start_path = i;
            }
            else{
                possible = 0;
            }
        }
        else if(outdegree[i]-indegree[i]==-1){
            if(end_path==0){
                end_path = i;
            }
            else{
                possible = 0;
            }
        }
        else if(outdegree[i]-indegree[i]!=0){
            possible = 0;
        }
    }   

    if(!possible || start_path!=1 || end_path!=n){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    dfs(1);
 
    if((int)path.size()!=m+1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    while(!path.empty()){
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
    
    return 0;
}