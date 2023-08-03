// 02/08/23 //
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

const int MAXN = (1e3) + 5;

int indegree[MAXN];
vector<int> adj[MAXN];

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    while(k--){
        int u, v;
        cin >> u >> v;

        adj[u].PB(v);
        indegree[v]++;
    }

    queue<int> fila;
    vector<int> resp;

    for(int i=0; i<n; i++){
        if(indegree[i]==0) fila.push(i);
    }

    while(!fila.empty()){
        if(fila.size()!=1) break;   

        int u = fila.front(); fila.pop();

        resp.PB(u);

        for(int v: adj[u]){
            indegree[v]--;

            if(indegree[v]==0) fila.push(v);
        }
    }

    if((int)resp.size()!=n){ 
        cout << "back to the lab" << endl; 
    }
    else{
        for(int i: resp) cout << i << " ";
        cout << endl;
    }
    
    return 0;
}
