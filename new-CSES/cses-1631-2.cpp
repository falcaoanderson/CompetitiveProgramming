// 11/06/23 // dp in tree
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

int n, dist[MAXN], diameter=0;
vector<int> graph[MAXN];

void dfs(int u, int last){
    dist[u] = 0;
    int maior=0, smaior=0;

    for(int v: graph[u]){
        if(v==last) continue;
        dfs(v, u);

        dist[u] = max(dist[u], dist[v]+1);
        
        if(maior<dist[v]+1){
            smaior = maior;
            maior = dist[v]+1;
        }
        else if(smaior<dist[v]+1){
            smaior = dist[v]+1;
        }
    }

    diameter = max(diameter, maior+smaior);
}

int main(){
    fast_io;

    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        graph[a].PB(b);
        graph[b].PB(a);
    }

    dfs(1, 0);

    cout << diameter << endl;

    return 0;
}
