// 11/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;
const int MAXM = (2e5) + 10;

int n, m, indegree[MAXN], outdegree[MAXN];
vector<int> path, adj[MAXN];

void eulerian_path(){
    stack<int> pilha;
    pilha.push(1);

    while(!pilha.empty()){
        int u = pilha.top();

        if(adj[u].empty()){
            path.pb(u);
            pilha.pop();
        }
        else{
            int v = adj[u].back();
            adj[u].pop_back();

            pilha.push(v);
        }
    }
}

int main(){
    fast_io;
    
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        outdegree[a]++;
        indegree[b]++;
    }

    bool possible = (outdegree[1]==indegree[1]+1) && (outdegree[n]+1==indegree[n]);
    for(int i=2; i<=n-1 && possible; i++)
        if(outdegree[i]!=indegree[i])
            possible = 0;
    
    if(!possible){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    eulerian_path();

    if((int)path.size()==m+1){
        for(int i=m; i>=0; i--)
            cout << path[i] << " ";
        cout << endl;
    }
    else    
        cout << "IMPOSSIBLE" << endl;

    return 0;
}