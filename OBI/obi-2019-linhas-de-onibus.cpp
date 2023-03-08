// 17/03/20 // 10:09 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = (int)(5e2) + 10;
const int INF = 0x3f3f3f3f;

int term, linhas, origem, destino;
int dist[2*MAXN];
vector<int> grafo[2*MAXN];
queue<int> fila;

void bfs(){
    fila.push(origem);
    dist[origem] = 0;

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for(int i : grafo[atual]){

            if(dist[i]!=-1) continue;

            dist[i] = dist[atual] + (atual<=term); // se tivermos trocando de linha aumenta em 1

            if(i==destino) return;

            fila.push(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dist, -1, sizeof(dist));

    cin >> term >> linhas >> origem >> destino;

    for(int i=1; i<=linhas; i++){ // para cada linha
        int tam;
        cin >> tam; // tamanho da linha

        for(int j=0; j<tam; j++){
            int v;
            cin >> v; // terminal que faz parte da linha i

            grafo[v].pb(i+term); // o terminal v faz parte da linha (i+term)
            grafo[i+term].pb(v);
        }
    }

    bfs();

    cout << dist[destino] << endl;

    return 0;
}
