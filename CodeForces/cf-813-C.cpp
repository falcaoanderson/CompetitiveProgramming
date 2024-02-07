// 24/01/24
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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

vector<int> adj[MAXN];
int dist[MAXN][5];

int main(){
    fast_io;

    int n, x;
    cin >> n >> x;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
        adj[b].PB(a);
    }

    queue<pii> fila;

    memset(dist, -1, sizeof(dist));

    fila.emplace(x, 1);
    fila.emplace(1, 0);
    dist[1][0] = 0;
    dist[x][1] = 0;

    while(!fila.empty()){
        int u = fila.front().FF;
        int id = fila.front().SS;
        fila.pop();

        for(int v: adj[u]){
            if(dist[v][id]==-1){
                dist[v][id] = dist[u][id] + ((id==1 && u==x)?1:2);
                fila.emplace(v, id);
            }
        }
    }

    int resp = 0;
   // cout << endl;
    for(int i=1; i<=n; i++){
        //cout << dist[i][0] << " " << dist[i][1] << endl;
        if(dist[i][1]+1<dist[i][0]){
            resp = max(resp, dist[i][0]);
        }
    }

    cout << resp << endl;


    return 0;
}
