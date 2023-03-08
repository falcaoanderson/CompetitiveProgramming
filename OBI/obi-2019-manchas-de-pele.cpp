// 05/03/20 // 08:51 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 1010;

int n, m, ma[MAXN][MAXN];
int aux[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool in_grid(int i, int j){
    return (i>=1 && i<=n && j>=1 && j<=m);
}

void dfs(int i, int j){
    for(int k=0; k<4; k++){
        int ni = i + aux[k][0];
        int nj = j + aux[k][1];

        if(in_grid(ni, nj) && ma[ni][nj]==1){
            ma[ni][nj] = 0;
            dfs(ni, nj);
        }
    }
}

void bfs(int i, int j){
    queue< pair<int , int> > fila;

    fila.push({i, j});

    while(!fila.empty()){
        i = fila.front().first;
        j = fila.front().second;
        fila.pop();

        for(int k=0; k<4; k++){
            int ni = i + aux[k][0];
            int nj = j + aux[k][1];

            if(in_grid(ni, nj) && ma[ni][nj]==1){
                ma[ni][nj] = 0;
                fila.push({ni, nj});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> ma[i][j];

    int resp = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(ma[i][j]==1){
                resp++;

                ma[i][j] = 0;
                dfs(i, j);
            }

    cout << resp << endl;

    return 0;
}
