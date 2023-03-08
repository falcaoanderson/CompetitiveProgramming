// 09/08/19 // 10:10 AM //

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 110
#define INF 0x3f3f3f3f
#define PB push_back
#define MP make_pair

typedef pair<int, int> pii;

int n, m;

vector< pii > grafo[MAXN];
bool visitado[MAXN];
int dist[MAXN];

void dijikstra(){

    for(int i=1; i<=n; i++)
        dist[i] = INF;
    dist[1] = 0;

    priority_queue< pii, vector<pii>, greater<pii> > fila;

    fila.push( MP(0,1) );

    while(true){
        int atual=-1;

        while(!fila.empty()){
            atual = (fila.top()).second;
            fila.pop();

            if(!visitado[atual]) break;

            atual = -1;
        }

        if(atual==-1) break;

        visitado[atual] = 1;

        for(int i=0; i<grafo[atual].size(); i++){
            int temp = grafo[atual][i].first;
            int dist_temp = dist[atual]  + grafo[atual][i].second;

            if(dist_temp < dist[temp]){
                dist[temp] = dist_temp;

                if(!visitado[temp]) fila.push( MP(dist[temp], temp) );
            }


        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, peso;

        cin >> a >> b >> peso;

        grafo[a].PB( MP(b, peso) );
        grafo[b].PB( MP(a, peso) );
    }

    dijikstra();

    cout << dist[n] << "\n";

    return 0;
}

