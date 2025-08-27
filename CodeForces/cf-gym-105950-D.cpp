/*
26/08/25 

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
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;

int n, m, maxval=0;
int grid[MAXN][316 + 5];
bool visited[MAXN][316 + 5];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool bfs(int sx, int sy, int mask){
    queue<pii> fila;
    fila.push({sx, sy});

    memset(visited, 0, sizeof(visited));

    while(!fila.empty()){
        int x = fila.front().FF, y = fila.front().SS;
        fila.pop();

        for(int k=0; k<4; k++){
            int nx=x+dx[k], ny=y+dy[k];

            if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny] && (grid[nx][ny]|mask)==mask){
                visited[nx][ny]=1;
                fila.push({nx, ny});
            }
        }
    }

    return visited[n-1][m-1];
}

int solve(int sx, int sy){
    int resp = maxval;

    for(int i=31; i>=0; i--){
        if(((1<<i)&resp)==0) continue;

        if(bfs(sx, sy, resp^(1<<i))){
            resp ^= (1<<i);
        }
    }

    return resp;
}

int main(){
    fast_io;

    int sx, sy;
    cin >> n >> m;
    cin >> sx >> sy;

    bool swaped = 0;
    if(m>n) swaped = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[(swaped?j:i)][(swaped?i:j)];
            maxval |= grid[(swaped?j:i)][(swaped?i:j)];
        }
    }
    if(swaped){
        swap(n, m);
        swap(sx, sy);
    }

    cout << solve(0, 0) << " " << solve(sx-1, sy-1) << endl;

    return 0;
}
