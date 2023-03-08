// 20/02/20 // 9:24 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define xx first
#define yy second.first
#define tt second.second

typedef pair<int, pair<int, int>> piii;

const int MAXN = 50 + 10;
const int MAXT = 10 + 10;
const int INF = 0x3f3f3f3f;

int aux_x[] = {-1, 0, 1,  0, 0,0};
int aux_y[] = { 0, 1, 0, -1, 0,0};

int n, m;
int ma[MAXN][MAXN];
int dist[MAXN][MAXN][MAXT];

bool in_grid(int x, int y){
    return (x>=1 && x<=n && y>=1 && y<=m);
}

void bfs(){
    memset(dist, INF, sizeof(dist));
    queue< piii > fila;

    dist[1][1][0] = 0;
    fila.push({1, {1, 0}});

    while(!fila.empty()){
        int x = fila.front().xx;
        int y = fila.front().yy;
        int t = fila.front().tt;
        fila.pop();

        for(int k=0; k<5; k++){
            int nx = x + aux_x[k];
            int ny = y + aux_y[k];
            int nt = (t+1)%10;

            if(!in_grid(nx, ny) || dist[nx][ny][nt]<INF ) continue;
            if((ma[x][y]+t)%10+1 < (ma[nx][ny]+t)%10)     continue;

            dist[nx][ny][nt] = dist[x][y][t] + 1;
            fila.push({nx, {ny, nt}});
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

    bfs();

    int resp = INF;
    for(int i=0; i<10; i++){
        resp = min(resp, dist[n][m][i]);
    }
    cout << resp << endl;

    return 0;
}

