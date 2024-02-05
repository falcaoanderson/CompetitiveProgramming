/*
25/01/24 
Problem: Denouncing Mafia
Complexity: O(n+m)
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
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int freq[MAXN], h[MAXN];
vector<int> adj[MAXN];

void dfs(int u){
    for(int v: adj[u]){
        dfs(v);

        h[u] = max(h[u], h[v]);
    }

    if(h[u] != 0) freq[h[u]]--;

    h[u]++;
    freq[h[u]]++;
}

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    for(int i=2; i<=n; i++){
        int a;
        cin >> a;

        adj[a].PB(i);
    }

    dfs(1);

    int resp=0;
    for(int i=n; i>=1 && k>0; i--){
        resp += i * min(k, freq[i]);
        k -= min(k, freq[i]);
    }

    cout << resp << endl;

    return 0;
}
