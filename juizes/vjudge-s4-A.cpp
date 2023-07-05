// 05/07/23 //
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

int pai[MAXN], dist[MAXN], tam[MAXN], id[MAXN];
ll sum[MAXN];

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
        tam[v] += tam[u];
        sum[v] += sum[u];
    }
    else{
        pai[v] = u;
        tam[u] += tam[v];
        sum[u] += sum[v];

        if(dist[u]==dist[v]) dist[u]++;
    }
}

int main(){
    fast_io;

    int n, m;
    while(cin >> n >> m){
        for(int i=1; i<=n; i++){
            id[i] = pai[i] = i;
            dist[i] = 0;
            tam[i] = 1;
            sum[i] = i;
        }

        while(m--){
            int op, u, v;
            cin >> op >> u;

            if(op==1){
                cin >> v;

                join(id[u], id[v]);
            }
            else if(op==2){
                cin >> v;

                if(find(id[u])==find(id[v])) continue;

                // id[u] vira um vertice 'fantasma'
                int pai_u = find(id[u]);
                sum[pai_u] -= (ll)u;
                tam[pai_u]--;

                // crio um novo id[u] e adiciono a v
                id[u] = (++n); pai[id[u]] = id[u]; dist[id[u]]=0; tam[id[u]] = 1; sum[id[u]] = u;
                join(id[u], id[v]);
            }
            else{
                u = find(id[u]);

                cout << tam[u] << " " << sum[u] << endl;
            }        
        }
    }

    return 0;
}
