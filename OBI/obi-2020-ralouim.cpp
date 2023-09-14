// Problema: OBI 2020 1 FASE - Ralouim
// 14/09/23 //
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

const int MAXN = (2e3) + 5;

int memo[MAXN][MAXN], aux[MAXN];
int x[MAXN], y[MAXN];

int dist(const pii &a){
    return (x[a.ff] - x[a.ss])*(x[a.ff] - x[a.ss]) + (y[a.ff] - y[a.ss])*(y[a.ff] - y[a.ss]);
}

bool comp(const pii &a, const pii &b){
    return dist(a) < dist(b);
}

int main(){
    fast_io;

    int n;
    cin >> n;

    x[0] = y[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }

    vector<pii> edges;
    for(int i=0; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            edges.EB(i, j);
        }
    }

    sort(edges.begin(), edges.end(), comp);

    // memo[u][v] := maior caminho partindo de u para v
    // aux[u]     := maior caminho partindo de u usando arestas com indice <= k

    int k=0, sz=edges.size();
    while(k<sz){

        // utiliza todas as arestas com a mesma distancia
        for(int i=k; i<sz && dist(edges[i])==dist(edges[k]); i++){
            int u = edges[i].ff, v = edges[i].ss;
            
            memo[u][v] = 1 + aux[v];

            if(u>0) memo[v][u] = 1 + aux[u];
        }

        int p=0;
        for(int i=k; i<sz && dist(edges[i])==dist(edges[k]); i++){
            int u = edges[i].ff, v = edges[i].ss;
            
            aux[u] = max(aux[u], memo[u][v]);
            
            if(u>0) aux[v] = max(aux[v], memo[v][u]);

            p++;
        }

        k+=p;
    }

    int resp = 0;
    for(int i=1; i<=n; i++){
        resp = max(resp, memo[0][i]);
    }

    cout << resp << endl;

    return 0;
}
