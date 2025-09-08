// 06/09/25

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define PB push_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e2+5;
int dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};

int n, m, k, sx, sy, ex, ey;
int dist[MAXN][MAXN];
bool grid[MAXN][MAXN];
vector<string> orders;
vector<pip> adj[MAXN][MAXN];

int dij(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j] = INF;
        }
    }
    
    priority_queue<pip, vector<pip>, greater<pip>> fila;
    fila.push({0, {sx, sy}});
    dist[sx][sy] = 0;
    // cout << "dijkstra" << endl;
    while(!fila.empty()){
        int x = fila.top().SS.FF, y = fila.top().SS.SS, d=fila.top().FF;
        fila.pop();

        // cout << x << " " << y << endl;

        if(d > dist[x][y]) continue;
        
        if(x==ex && y==ey) break;

        for(pip e: adj[x][y]){
            int w = e.FF, nx = e.SS.FF, ny = e.SS.SS;
            // cout << w << " " << nx << " " << ny << endl;
            if(dist[x][y]+w < dist[nx][ny]){
                dist[nx][ny] = dist[x][y]+w;

                fila.push({dist[nx][ny], {nx, ny}});
            }
        }
        // cout << endl;
    }

    return (dist[ex][ey]<INF?dist[ex][ey]:-1);
}

int main() {
    fast_io;

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;
            grid[i][j] = (c=='1');
        }
    }

    cin >> sx >> sy >> ex >> ey;
    
    cin >> k;
    for(int i=0; i<k; i++){
        string s;
        cin >> s;
        for(char& c: s){
            if(c=='U') c = 'a';
            if(c=='R') c = 'b';
            if(c=='D') c = 'c';
            if(c=='L') c = 'd';
        }
        // cout << s << endl;
        orders.PB(s); 
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]) continue;
            // cout << i << " " << j << endl;

            for(string order: orders){
                int w=0, x=i, y=j, nx, ny;

                for(char o: order){
                    nx = x+dx[o-'a']; 
                    ny = y+dy[o-'a'];

                    if(0<=nx && nx<n && 0<=ny && ny<m && !grid[nx][ny]){
                        w++;
                        x = nx;
                        y = ny;
                    }
                }
                
                if(x!=i || y!=j) {
                    // cout << w << " " << x << " " << y << endl;
                    adj[i][j].PB({w, {x, y}});
                }
            }

            // cout << endl;
        }
    }

    cout << dij() << endl;

    return 0;
}