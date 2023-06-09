// 09/06/23 // algoritmo de kruskal
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

int pai[MAXN], dist[MAXN];

int find(int u){
    if(pai[u]==u) return u;

    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return;

    if(dist[u]<dist[v]){
        pai[u] = v;
    }
    else if(dist[u]>dist[v]){
        pai[v] = u;
    }
    else{
        pai[u] = v;
        dist[v]++;
    }
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    vector<tiii> edges;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        edges.EB(c, a, b);
    }

    sort(edges.begin(), edges.end());

    for(int i=1; i<=n; i++) pai[i] = i;    
    
    ll resp = 0LL;
    int qnt=0;

    for(tiii edge: edges){
        int a, b, c;
        tie(c, a, b) = edge;

        if(find(a)!=find(b)){
            resp += (ll)c;
            
            qnt++;
            if(qnt==n-1) break;

            join(a, b);
        }
    }

    if(qnt==n-1){
        cout << resp << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
