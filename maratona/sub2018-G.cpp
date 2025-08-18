/*
17/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    int weight=0;
    FlowEdge(int v, int u, long long cap, int weight) : v(v), u(u), cap(cap), weight(weight){}
};
struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void reset_flow(){
        level.assign(n, 0);
        ptr.assign(n, 0);
        while(!q.empty()) q.pop();
        for(auto &e: edges) e.flow = 0;
    }

    void add_edge(int v, int u, long long cap, int weight) {
        edges.emplace_back(v, u, cap, weight);
        edges.emplace_back(u, v, 0, weight);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs(int max_weight) {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap == edges[id].flow || edges[id].weight>max_weight)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed, int max_weight) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].weight>max_weight)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow), max_weight);
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow(int max_weight) {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs(max_weight))
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf, max_weight)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main(){
    fast_io;

    int p, r, c;
    cin >> p >> r >> c;

    int n = p+r+2;
    Dinic dinic(n, 0, n-1);
    int goal=0;

    for(int i=r+1; i<=r+p; i++){
        int x;
        cin >> x;
        dinic.add_edge(i, n-1, x, 0);
        goal += x;
    }
    for(int i=1; i<=r; i++){
        int x;
        cin >> x;
        dinic.add_edge(0, i, x, 0);
    }

    set<int> tset;
    for(int i=0; i<c; i++){
        int u, v, t;
        cin >> u >> v >> t;

        dinic.add_edge(v, u+r, goal, t);
        tset.insert(t);
    }

    vector<int> vt;
    for(int x: tset) vt.PB(x);
    int left=0, right=(int)vt.size()-1, resp=-1;

    while(left<=right){
        int mid = (left+right)/2;
        // cout << left << " " << right << endl;
        int mflow = dinic.flow(vt[mid]);
        dinic.reset_flow();
        // cout << mflow << endl;
        if(mflow>=goal){
            resp = vt[mid];
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    cout << resp << endl;

    return 0;
}
