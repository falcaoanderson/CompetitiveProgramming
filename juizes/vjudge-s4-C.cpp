// 22/06/23 // union-find
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

int pai[MAXN], tam[MAXN], dist[MAXN];

int find(int u){
    if(pai[u]==u) return u;

    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return;

    if(dist[u]<=dist[v]){
        pai[u] = v;
        tam[v] += tam[u];
    
        if(dist[u]==dist[v]) dist[v]++;
    }
    else{
        pai[v] = u;
        tam[u] += tam[v];
    }
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<pair<string, string> > edges(n);
        unordered_map<string, int> id;
        int qnt = 0;

        for(int i=0; i<n; i++){
            cin >> edges[i].ff >> edges[i].ss;

            if(id.find(edges[i].ff)==id.end()) id[edges[i].ff] = (++qnt);
            if(id.find(edges[i].ss)==id.end()) id[edges[i].ss] = (++qnt);
        }

        for(int i=1; i<=qnt; i++){
            pai[i] = i;
            tam[i] = 1;
            dist[i] = 0;
        }

        for(int i=0; i<n; i++){
            int u = find(id[edges[i].ff]), v = find(id[edges[i].ss]);

            join(u, v);

            cout << tam[find(u)] << endl;
        }       
    }

    return 0;
}