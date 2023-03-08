// 09/10/20 // 19:47 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (5e2) + 10;

int n, e, s, m;
int dist[MAXN][5];
vector< pair<int, bool> > grafo[MAXN];

void bfs(){
    queue<pair<int, int>> fila;
    memset(dist, -1, sizeof(dist));

    fila.push(mp(e, 0));
    dist[e][0] = 0;

    while(!fila.empty()){
        int u = fila.front().first;
        int tempo = fila.front().second;
        fila.pop();

        for(int i=0; i<(int)grafo[u].size(); i++){
            int v    = grafo[u][i].first;
            int tipo = grafo[u][i].second;

            if((tempo%3==0 && tipo==0) || (tempo%3!=0 && tipo==1))
                continue;

            if(dist[v][(tempo+1)%3]==-1){
                dist[v][(tempo+1)%3] = tempo + 1;

                fila.push(mp(v, tempo+1));
            }
        }
    }

    if(dist[s][0]==-1) dist[s][0] = INF;
    if(dist[s][1]==-1) dist[s][1] = INF;
    if(dist[s][2]==-1) dist[s][2] = INF;
    int resp = min(dist[s][0], min(dist[s][1], dist[s][2]));

    if(resp==INF) cout << "*" << endl;
    else          cout << resp << endl;
}

int main(){
    fast_io;

    cin >> n >> e >> s >> m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        grafo[a].pb(mp(b, c));
    }

    bfs();

    return 0;
}
