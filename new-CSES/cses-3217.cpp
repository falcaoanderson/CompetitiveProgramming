/*
22/08/25 

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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int grid[MAXN][MAXN];
int dx[] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dy[] = {-1, 1, 2, 2, -1, 1, -2, -2};

int main(){
    fast_io;

    int n;
    cin >> n;

    queue<pii> fila;
    fila.push({0, 0});
    while(!fila.empty()){
        int x = fila.front().FF, y=fila.front().SS;
        fila.pop();

        for(int k=0; k<8; k++){
            int nx = x+dx[k], ny = y+dy[k];

            if(0<=nx && nx<n && 0<=ny && ny<n && nx+ny!=0 && grid[nx][ny]==0){
                grid[nx][ny] = grid[x][y]+1;
                fila.push({nx, ny});
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
