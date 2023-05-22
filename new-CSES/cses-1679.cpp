// 22/05/23 // O(n+m)
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

int indegree[MAXN];
vector<int> graph[MAXN];

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

    queue<int> qqueue;

    for(int i=1; i<=n; i++){
        if(indegree[i]==0) qqueue.push(i);
    }

    vector<int> resp;

    while(!qqueue.empty()){
        int u = qqueue.front();
        qqueue.pop();

        resp.PB(u);

        for(int v: graph[u]){
            indegree[v]--;

            if(indegree[v]==0) qqueue.push(v);
        }
    }

    if((int)resp.size() == n){
        for(int i: resp) cout << i << " ";
        cout << endl;
    }
    else 
        cout << "IMPOSSIBLE" << endl;

    return 0;  
}
