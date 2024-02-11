// 02/02/24 //
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
const int MAXN = (5e2) + 5;
const int MOD  = (1e9) + 7;

int age[MAXN], id[MAXN], rev_id[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];

int dfs(int u){
    visited[u] = 1;
    int resp = INF;

    for(int v: adj[u]){
        if(visited[v]) continue;

        resp = min(resp, min(age[id[v]], dfs(v)));
    }

    return resp;
}

int main(){
    fast_io;

    int n, m, q;
    while(cin >> n >> m >> q){
        if(n==0) break;

        for(int i=1; i<=n; i++) adj[i].clear();

        for(int i=1; i<=n; i++){
            cin >> age[i];

            id[i] = rev_id[i] = i;
        }

        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;

            adj[b].PB(a);
        }

        while(q--){
            char op;
            cin >> op;

            if(op=='T'){
                int a, b;
                cin >> a >> b;

                swap(id[rev_id[a]], id[rev_id[b]]);
                swap(rev_id[a], rev_id[b]);
            }
            else{
                int a;
                cin >> a;

                memset(visited, 0, sizeof(visited));
                a = dfs(rev_id[a]);

                if(a==INF) cout << "*" << endl;
                else       cout << a << endl;
            }
        }
    }

    return 0;
}
