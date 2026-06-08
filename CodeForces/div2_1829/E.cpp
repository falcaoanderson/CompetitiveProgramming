/*
20/01/26

*/
#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e3 + 5;
const int MAXN = 1e3 + 5;

bool visited[MAXN][MAXN];
int n, m, grid[MAXN][MAXN];
int dx[] = {-1, 0, 1, 0, 0, 0}, dy[] = {0, 1, 0, -1, 0, 0};

int bfs(int x, int y){
    queue<pii> fila;
    
    visited[x][y] = 1;
    fila.push({x, y});
    
    int resp = 0;

    while(!fila.empty()){
        x = fila.front().FF, y = fila.front().SS;
        fila.pop();

        resp += grid[x][y];
        
        for(int k=0; k<4; k++){
            int nx = x + dx[k], ny = y + dy[k];

            if(1<=nx && nx<=n && 1<=ny && ny<=m && 
            !visited[nx][ny] && grid[nx][ny]>0){
                
                visited[nx][ny] = 1;
                fila.push({nx, ny});
            }
        }
    }

    return resp;
}

void solve(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> grid[i][j];
        }
    }

    int resp = 0;
    memset(visited, 0, sizeof(visited));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!visited[i][j] && grid[i][j]>0){
                resp = max(resp, bfs(i, j));
            }
        }
    }

    cout << resp << endl;
}

int main(){
    fast_io;

    int t; 
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}