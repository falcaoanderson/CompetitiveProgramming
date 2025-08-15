/*
13/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 55;
const int MOD  = (1e9) + 7;

int n, grid[MAXN][MAXN];
int aux_x[] = {0, -1, 0, 1, 0, 0};
int aux_y[] = {-1, 0, 1, 0, 0, 0};

void dfs(int x, int y){
    for(int k=0; k<4; k++){
        int nx = x + aux_x[k];
        int ny = y + aux_y[k];

        if(1<=nx && nx<=n && 1<=ny && ny<=n && grid[nx][ny]==0){
            grid[nx][ny] = grid[x][y];
            dfs(nx, ny);
        }
    }
}

int main(){
    fast_io;

    int sx, sy, ex, ey;

    cin >> n;
    cin >> sx >> sy >> ex >> ey;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c;
            cin >> c;
            grid[i][j] = (c-'0');
        }
    }

    grid[sx][sy] = 2;
    dfs(sx, sy);

    if(grid[ex][ey]==2){
        cout << 0 << endl;
        return 0;
    }

    grid[ex][ey] = 3;
    dfs(ex, ey);

    int resp = INF;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
     
            for(int x=1; x<=n; x++){
                for(int y=1; y<=n; y++){
                    
                    if(grid[i][j]==2 && grid[x][y]==3){
                        resp = min(resp, (i-x)*(i-x)+(j-y)*(j-y));
                    }
                }
            }
     
        }
    }
    cout << resp << endl;

    return 0;
}
