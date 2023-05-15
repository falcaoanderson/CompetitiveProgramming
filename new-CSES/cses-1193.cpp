// 15/05/23 // BFS // O(n*m)
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
char grid[MAXN][MAXN];

int aux_x[] = {-1, 0, 1,  0,   0, 0};
int aux_y[] = { 0, 1, 0, -1,   0, 0};
char auxc[] = {'U', 'R', 'D', 'L', 'x', 'x'};
int sx, sy, fx, fy;

void bfs(int x, int y){
    queue<pii> v;
    v.emplace(x, y);
    
    bool flag = false;

    while(!v.empty() && !flag){
        x = v.front().first;
        y = v.front().second;
        v.pop();

        for(int i=0; i<4; i++){
            int nx = x + aux_x[i];
            int ny = y + aux_y[i];

            if(0<nx && nx<=n && 0<ny && ny<=m){
                if(grid[nx][ny]=='.'){
                    grid[nx][ny] = auxc[i];
                    v.emplace(nx, ny);              
                }
                else if(grid[nx][ny]=='B'){
                    grid[nx][ny] = auxc[i];
                    flag = true;
                    break;
                }
            }
        }
    }

    if(flag==false){
        cout << "NO" << endl;
        return;
    }

    x = fx;
    y = fy;
    string resp = "";

    while(x!=sx || y!=sy){
        resp += grid[x][y];

        if(grid[x][y]=='U'){
            x++;
        }
        else if(grid[x][y]=='R'){
            y--;   
        }
        else if(grid[x][y]=='D'){
            x--;
        }
        else if(grid[x][y]=='L'){
            y++;
        }
    }

    cout << "YES" << endl;
    cout << resp.size() << endl;

    for(int i=resp.size()-1; i>=0; i--) cout << resp[i];
    cout << endl;
}
 
int main(){
    fast_io;
 
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> grid[i][j];

            if(grid[i][j]=='A'){
                sx = i;
                sy = j;
            }
            else if(grid[i][j]=='B'){
                fx = i;
                fy = j;
            }
        }
    }
 
    bfs(sx, sy);
 
    return 0;
}