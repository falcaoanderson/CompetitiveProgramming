// 24/05/23 //
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

const int MAXN = (2e5) + 5;

int n;
vector<int> graph[MAXN];
int qnt[MAXN];

void dfs(int u){
    qnt[u] = 0;
    
    for(int v: graph[u]){
        dfs(v); 

        qnt[u] += 1 + qnt[v];
    }
}

int main(){
    fast_io;
    
    cin >> n;

    for(int i=2; i<=n; i++){
        int x;
        cin >> x;

        graph[x].PB(i);
    }

    dfs(1);

    for(int i=1; i<=n; i++){
        cout << qnt[i] << " ";
    }
    cout << endl;

    return 0;
}
