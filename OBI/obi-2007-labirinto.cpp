// 20/02/20 // 9:24 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 50 + 10;
const int MAXT = 10 + 10;
const int INF = 0x3f3f3f3f;

int aux_x[] = {-1, 0, 1,  0, 0,0};
int aux_y[] = { 0, 1, 0, -1, 0,0};

int n, m;
int ma[MAXN][MAXN];
int memo[MAXN][MAXN][MAXT];

bool in_grid(int x, int y){
    return (x>=1 && x<=n && y>=1 && y<=m);
}

void dfs(int x, int y, int t){
    if(x==n && y==m) return;

    for(int k=0; k<4; k++){
        int nx = x + aux_x[k];
        int ny = y + aux_y[k];

        if(!in_grid(nx, ny)) continue;

        int espera = ((t+ma[x][y])%10 + 1 >= (t+ma[nx][ny])%10 ? 0 : 10 - (t+ma[nx][ny])%10);

        if(memo[nx][ny][(t+1+espera)%10] > 1+espera+memo[x][y][t]){

            memo[nx][ny][(t+1+espera)%10] = 1+espera+memo[x][y][t];
            dfs(nx, ny, (t+1+espera)%10);
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            cin >> ma[i][j];
    }

    memset(memo, INF, sizeof(memo));
    memo[1][1][0] = 0;
    dfs(1, 1, 0);

    int resp = INF;
    for(int i=0; i<10; i++){
        resp = min(resp, memo[n][m][i]);
    }
    cout << resp << endl;

    return 0;
}
