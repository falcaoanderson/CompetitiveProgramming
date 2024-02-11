/*
07/02/24 
Problem: 
Complexity:
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
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

vector<int> adj[MAXN];
int tt=0, in[MAXN], low[MAXN];
bool is_cut[MAXN];

void dfs(int u, int p){
    in[u] = low[u] = (++tt);

    //cout << "dfs: " << u << endl;

    int qnt_filhos=0;
    for(int v: adj[u]){
        if(v==p) continue;

        if(low[v]==0){ //filho
            //cout << "   filho: " << v << endl;
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if(low[v]>=in[u]){
                is_cut[u] = 1;
            }

            qnt_filhos++;
        }
        else if(in[v]<in[u]){ //backedge
            //cout << "   backedge: " << v << endl;
            low[u] = min(low[u], in[v]);
        }
    }

    if(u==1){
        is_cut[u] = (qnt_filhos>=2);
    }
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
    
        adj[a].PB(b);
        adj[b].PB(a);
    }

    dfs(1, 0);

    int qnt = 0;
    for(int i=1; i<=n; i++) qnt += (int)is_cut[i];
    cout << qnt << endl;

    for(int i=1; i<=n; i++) if(is_cut[i]) cout << i << " ";
    cout << endl;

    return 0;
}
