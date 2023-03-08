// 16/02/19 // 2:16 PM //

#include <iostream>

using namespace std;

#define MAXN 510

int n, nao_seguro=0;
int matriz[MAXN][MAXN], visitado[MAXN][MAXN];
int aux_i[6] = {-1, 0, 1, 0, 0, 0};
int aux_j[6] = {0, 1, 0, -1, 0, 0};
int seta[6]  = {3, 4, 1, 2, 0, 0};

int dfs(int i, int j){
    int new_i, new_j;

    visitado[i][j]=1;
    nao_seguro++;

    for(int k=0; k<4; k++){
        new_i = i + aux_i[k];
        new_j = j + aux_j[k];

        if(matriz[new_i][new_j]==seta[k] && !visitado[new_i][new_j]){
            dfs(new_i, new_j);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char temp;
            cin >> temp;
            if     (temp=='V') matriz[i][j] = 3;
            else if(temp=='<') matriz[i][j] = 4;
            else if(temp=='>') matriz[i][j] = 2;
            else if(temp=='A') matriz[i][j] = 1;
        }
    }

    if(n==1){
        cout << "0\n";
        return 0;
    }

    for(int j=1; j<=n; j++){ // primeira linha //
        if(j==1){
            if( (matriz[1][j]==4 || matriz[1][j]==1) && !visitado[1][j]) // superior esquerdo
                dfs(1,j);

            if( (matriz[n][j]==4 || matriz[n][j]==3) && !visitado[n][j]) // inferior esquerdo
                dfs(n,j);
        }
        else if(j==n){
            if( (matriz[1][j]==2 || matriz[1][j]==1) && !visitado[1][j]) // superior direito
                dfs(1,j);

            if( (matriz[n][j]==2 || matriz[n][j]==3) && !visitado[n][j]) // inferior direito
                dfs(n,j);
        }
        else{
            if( matriz[1][j]==1 && !visitado[1][j]) // superior
                dfs(1,j);

            if( matriz[n][j]==3 && !visitado[n][j]) // inferior
                dfs(n,j);
        }
    }

    for(int i=2; i<n; i++){
        if(matriz[i][1]==4 && !visitado[i][1])
            dfs(i,1);

        if(matriz[i][n]==2 && !visitado[i][n])
            dfs(i,n);
    }

    cout << n*n - nao_seguro << "\n";

    return 0;
}
