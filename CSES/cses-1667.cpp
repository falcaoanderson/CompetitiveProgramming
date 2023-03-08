// 04/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m;
vector<int> grafo[MAXN];
int dist[MAXN], anterior[MAXN];

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    queue<int> fila;
    fila.push(1);
    anterior[1] = 1;
    dist[1] = 0;

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        if(u==n) break;

        for(int v: grafo[u]){
            if(anterior[v]==0){
                anterior[v] = u;
                dist[v] = dist[u] + 1;
                
                fila.push(v);
            }
        }
    }

    if(dist[n]==0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << dist[n] + 1 << endl;

        int u=n;
        stack<int> caminho;
        
        while(u!=1){
            caminho.push(u);
            u = anterior[u];
        }
        caminho.push(1);

        while(!caminho.empty()){
            cout << caminho.top() << " ";
            caminho.pop();
        }
        cout << endl;
    }

    return 0;
}
