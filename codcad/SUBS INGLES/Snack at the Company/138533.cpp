// 13/02/19 // 8:37 PM //

#include <iostream>

using namespace std;

#define MAXV 260
#define INF 999999999

int nver, nare;
int adj[MAXV][MAXV];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nver >> nare;

    for(int i=1; i<=nver; i++){
        for(int j=1; j<=nver; j++)
            adj[i][j] = INF;

        adj[i][i] = 0;
    }

    for(int i=0; i<nare; i++){
        int a, b, c;

        cin >> a >> b >> c;

        adj[a][b] = adj[b][a] = c;
    }

    for(int k=1; k<=nver; k++)
        for(int i=1; i<=nver; i++)
            for(int j=1; j<=nver; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);


    int linha=0, geral=INF;
    for(int i=1; i<=nver; i++){
        for(int j=1; j<=nver; j++)
            linha = max(linha, adj[i][j]);
        geral = min(geral, linha);
        linha = 0;
    }

    cout << geral << "\n";

    return 0;
}
