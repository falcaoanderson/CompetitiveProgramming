/*
Date: 02/11/23 
Problem: LCA with euler tour technique and sparse table
Complexity: <O(nlogn), O(1)>
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

const int MAXN = (2e5) + 5;
const int MAXLOG = 17 + 5;

int n;
vector<int> adj[MAXN];
int lvl[MAXN];
int euler_tour_id[2*MAXN], first_pos[MAXN];
int st_id[2*MAXN][MAXLOG];

int sz=0;
void dfs(int u, int last){
    euler_tour_id[++sz] = u;
    first_pos[u] = sz;

    for(int v: adj[u]){
        if(v==last) continue;

        lvl[v] = lvl[u]+1;
        dfs(v, u);

        euler_tour_id[++sz] = u;
    } 
}

inline int ilog2(int a){
    return 31-__builtin_clz(a);
}

void build_st(){
    for(int i=1; i<=sz; i++){
        st_id[i][0]  = euler_tour_id[i];
    }

    for(int k=1; k<=ilog2(sz); k++){
        for(int i=1; i+(1<<k)-1<=sz; i++){
            st_id[i][k]  = (lvl[ st_id[i][k-1] ]<=lvl[ st_id[i+(1<<(k-1))][k-1] ]? st_id[i][k-1]: st_id[i+(1<<(k-1))][k-1]);
        }
    }
}

int lca(int u, int v){
    int i = first_pos[u];
    int j = first_pos[v];
    if(i>j) swap(i, j);

    int l = ilog2(j-i+1);
    
    return (lvl[ st_id[i][l] ]<lvl[ st_id[j-(1<<l)+1][l] ] ? st_id[i][l]: st_id[j-(1<<l)+1][l]);
}

int main(){
    fast_io;

    int q;
    cin >> n >> q;

    for(int b=2; b<=n; b++){
        int a;
        cin >> a;

        adj[a].PB(b);
    }

    dfs(1, 0);
    build_st();

    while(q--){
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << endl;
    }

    return 0;
}
