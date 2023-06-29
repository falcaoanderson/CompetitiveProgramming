// 29/06/23 //
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

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = 30 + 5;

bool grid[MAXN][MAXN];

int main(){
    fast_io;

    int n, m, k;
    cin >> m >> n >> k;

    for(int i=0; i<k; i++){
        int c, l;
        char d;
        cin >> c >> l >> d;

        if(d=='N'){
            for(int x=l; x>=1; x--) grid[x][c]=1;
        }
        else if(d=='S'){
            for(int x=l; x<=n; x++) grid[x][c]=1;
        }
        else if(d=='L'){
            for(int y=c; y<=m; y++) grid[l][y]=1;
        }
        else{
            for(int y=c; y>=1; y--) grid[l][y]=1;
        }
    }
    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    */

    queue<pii> fila;
    if(grid[1][1]==0 && grid[n][m]==0){
        grid[1][1] = 1;
        fila.emplace(1, 1);
    }
    else{
        cout << "N" << endl;
        return 0;
    }

    vector<int> aux_x = {-1, 0, 1, 0};
    vector<int> aux_y = {0, 1, 0, -1};

    while(!fila.empty()){
        int x = fila.front().ff, y=fila.front().ss;
        fila.pop();

        for(int i=0; i<4; i++){
            int nx = x + aux_x[i];
            int ny = y + aux_y[i];

            if(1<=nx && nx<=n && 1<=ny && ny<=m && grid[nx][ny]==0){
               grid[nx][ny]=1;
               fila.emplace(nx, ny); 
            }
        }
    }

    cout << (grid[n][m]? "S": "N") << endl;

    return 0;
}
