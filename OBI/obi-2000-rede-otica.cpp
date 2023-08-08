// 08/08/2023 // 
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define PB push_back
#define EB emplace_back

typedef tuple<int, int, int> tiii;

const int MAXN = 1e2+5;

int pai[MAXN], dist[MAXN];

int find(int u){
    if(pai[u]==u) return u;

    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return;

    if(dist[u]>=dist[v]){
        pai[v] = u;

        if(dist[u]==dist[v]) dist[u]++;
    }
    else{
        pai[u] = v;
    }
}

void solve(int n, int m){
    for(int i=1; i<=n; i++){
        pai[i] = i;
        dist[i] = 0;
    }

    vector<tiii> edges;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        if(u>v) swap(u, v);

        edges.EB(w, u, v);
    }

    sort(edges.begin(), edges.end());

    vector< pair<int, int> > resp;

    for(tiii edge: edges){
        int w, u, v;
        tie(w, u, v) = edge;

        if(find(u)==find(v)) continue;

        join(u, v);
        resp.EB(u, v);
    }

    for(auto edge: resp){
        cout << edge.first << " " << edge.second << endl;
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, id=0;
    while(true){
        cin >> n >> m;

        if(n==0) break;

        cout << "Teste " << (++id) << endl;
        solve(n, m);
        cout << endl;
    }


    return 0;
}
