// 16/02/19 // 1:41 PM //

#include <iostream>

using namespace std;

#define MAXN 60

int n;
int matriz[MAXN][MAXN], linhas[MAXN], colunas[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> matriz[i][j];
            linhas[i]  += matriz[i][j];
            colunas[j] += matriz[i][j];
        }
    }

    int soma_certa;

    if(linhas[1]==linhas[2] && linhas[2]==linhas[3]) soma_certa = linhas[1];
    else if(linhas[1]!=linhas[2] && linhas[2]==linhas[3]) soma_certa = linhas[2];
    else if(linhas[1]!=linhas[2] && linhas[1]==linhas[3]) soma_certa = linhas[1];
    else if(linhas[1]==linhas[2] && linhas[2]!=linhas[3]) soma_certa = linhas[1];

    int x, y;
    for(int i=1; i<=n; i++){
        if(linhas[i]!=soma_certa)
            x = i;
        if(colunas[i]!=soma_certa)
            y = i;
    }

    cout << soma_certa - (linhas[x] - matriz[x][y]) << " " << matriz[x][y] << "\n";

    return 0;
}
