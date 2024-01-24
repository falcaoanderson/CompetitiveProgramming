#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int n, m, k;
bool grid[MAXN][MAXN];
int qnt[(int)1e6 + 5],  qnt_color, color[MAXN][MAXN];

int aux_x[] = {-1, 0, 1, 0, 0, 0};
int aux_y[] = {0, 1, 0, -1, 0, 0};

int bfs(int x, int y){
    if(color[x][y]!=0){
        return qnt[color[x][y]];
    }
    qnt_color++;

    queue<pii> fila;
    fila.emplace(x, y);

    while(!fila.empty()){
        x = fila.front().FF;
        y = fila.front().SS;
        fila.pop();

        if(color[x][y]!=0) continue;

        color[x][y] = qnt_color;

        for(int i=0; i<4; i++){
            int nx = x + aux_x[i];
            int ny = y + aux_y[i];

            if(grid[nx][ny] && color[nx][ny]==0){
                fila.emplace(nx, ny);
            }
            if(!grid[nx][ny]){
                qnt[qnt_color]++;   
            }
        }
    }

    return qnt[qnt_color];
}
int main(){
    fast_io;

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char c;
            cin >> c;

            grid[i][j] = (c=='.');
        }
    }

    while(k--){
        int i, j;
        cin >> i >> j;

        cout << bfs(i, j) << endl;
    }

    return 0;
}
