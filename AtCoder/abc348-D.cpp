/*
12/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
const int MAXN = (2e2) + 5;
const int MOD  = (1e9) + 7;

int n, m;
int energy[MAXN][MAXN], visited[MAXN][MAXN];
int aux_x[] = {0, -1, 0, 1,0,0};
int aux_y[] = {-1, 0, 1, 0,0,0};
char grid[MAXN][MAXN];

bool bfs(int x, int y, int e){
    queue< pair<pii, int> > fila;
    fila.push({{x, y}, e});
    bool resp = 0;

    while(!fila.empty()){
        x = fila.front().FF.FF;
        y = fila.front().FF.SS;
        e = fila.front().SS;
        fila.pop();

        if(visited[x][y]>=e) continue;
        visited[x][y] = e;
            
        if(grid[x][y]=='T'){
            resp = 1;
            break;
        }
        
        if(energy[x][y]>e){
            fila.push({{x, y}, energy[x][y]});
            continue;
        }

        if(e<1) continue;

        for(int k=0; k<4; k++){
            int nx = x + aux_x[k];
            int ny = y + aux_y[k];
            
            if(1<=nx && nx<=n && 1<=ny && ny<=m &&
                grid[nx][ny]!='#' && visited[nx][ny]<e-1){

                fila.push({{nx, ny}, e-1});
            }
        }
    }

    return resp;
}

int main(){
    fast_io;

    cin >> n >> m;
    
    int sx=0, sy=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> grid[i][j];

            if(grid[i][j]=='S'){
                sx = i;
                sy = j;
            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int x, y, e;
        cin >> x >> y >> e;

        energy[x][y] = e;
    }

    memset(visited, -1, sizeof(visited));
    bool resp = bfs(sx, sy, 0);
    cout << (resp?"Yes":"No") << endl;
    
    return 0;
}