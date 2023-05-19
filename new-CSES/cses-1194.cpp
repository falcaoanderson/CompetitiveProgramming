// 19/05/23 // bfs // o(n*m);
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

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define ll long long

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (1e3) + 5;

int n, m;
int start_x, start_y;
char grid[MAXN][MAXN];
int distm[MAXN][MAXN], diste[MAXN][MAXN];
char path[MAXN][MAXN];

char direction[] = {'U', 'R', 'D', 'L', '0', '0'};
int aux_x[] = {-1, 0, 1, 0,   0, 0};
int aux_y[] = {0, 1, 0, -1,   0, 0};

bool in_grid(int i, int j){
    return (1<=i && i<=n && 1<=j && j<=m && grid[i][j]!='#');
}

void bfs_m(int x, int y){
    queue<pii> fila;
    fila.emplace(x, y);
    distm[x][y] = 0;

    while(!fila.empty()){
        x = fila.front().first; y = fila.front().second;
        fila.pop();

        for(int i=0; i<4; i++){
            int nx = x + aux_x[i];
            int ny = y + aux_y[i];

            if(in_grid(nx, ny) && (distm[nx][ny]==-1 || distm[x][y]+1<distm[nx][ny])){
                distm[nx][ny] = (grid[nx][ny]=='M'? 0: distm[x][y] + 1);

                fila.emplace(nx, ny);
            }
        }
    }
}

void bfs_e(int x, int y){
    queue<pii> fila;
    fila.emplace(x, y);
    diste[x][y] = 0;

    while(!fila.empty()){
        x = fila.front().first; y = fila.front().second;
        fila.pop();

        for(int i=0; i<4; i++){
            int nx = x + aux_x[i];
            int ny = y + aux_y[i];

            if(in_grid(nx, ny) && diste[nx][ny]==-1){
                diste[nx][ny] = diste[x][y] + 1;

                path[nx][ny] = direction[i]; 

                fila.emplace(nx, ny);
            }
        }
    }
}

int main(){
    fast_io;

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> grid[i][j];

            if(grid[i][j]=='A'){
                start_x = i;
                start_y = j;
            }
        }
    }

    memset(distm, -1, sizeof(distm));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(grid[i][j]=='M' && distm[i][j]!=0) bfs_m(i, j);
        }
    }

    memset(diste, -1, sizeof(diste));
    bfs_e(start_x, start_y);

    int x=-1, y=-1;
    for(int i=1; i<=n && x==-1; i++){
        if(diste[i][1]!=-1 && (distm[i][1]==-1 || diste[i][1]<distm[i][1])){
            x=i;
            y=1;
        }
        else if(diste[i][m]!=-1 && (distm[i][m]==-1 || diste[i][m]<distm[i][m])){
            x=i;
            y=m;
        }
    }
    for(int j=1; j<=m && x==-1; j++){
        if(diste[1][j]!=-1 && (distm[1][j]==-1 || diste[1][j]<distm[1][j])){
            x=1;
            y=j;
        }
        else if(diste[n][j]!=-1 && (distm[n][j]==-1 || diste[n][j]<distm[n][j])){
            x=n;
            y=j;
        }
    }

    if(x==-1){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    string resp = "";
    while(!(x==start_x && y==start_y)){
        resp += path[x][y];

        for(int i=0; i<4; i++){
            if(path[x][y]==direction[i]){
                x -= aux_x[i];
                y -= aux_y[i];
                break;
            }
        }
    }

    cout << resp.size() << endl;

    for(int i=(int)resp.size()-1; i>=0; i--){
        cout << resp[i];
    }
    cout << endl;
    

    return 0;
}