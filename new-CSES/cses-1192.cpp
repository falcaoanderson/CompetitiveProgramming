// 14/05/23 // dfs // O(n*m)
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
bool grid[MAXN][MAXN];
int aux_x[] = {-1, 0, 1,  0,   0, 0};
int aux_y[] = { 0, 1, 0, -1,   0, 0};

void dfs(int x, int y){ 
    grid[x][y] = 0;

    for(int i=0; i<4; i++){
        int nx = x + aux_x[i];
        int ny = y + aux_y[i];

        if(0<nx && nx<=n && 0<ny && ny<=m && grid[nx][ny]){
            dfs(nx, ny);
        }
    }
}

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char temp;
            cin >> temp;

            grid[i][j] = (temp=='.');
        }
    }

    int cont=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(grid[i][j]){
                cont++;

                dfs(i, j);
            }
        }
    }

    cout << cont << endl;

    return 0;
}
