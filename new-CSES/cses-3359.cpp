/*
06/09/25 

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

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int dx[] = {0, 1}, dy[] = {1, 0};

int main(){
    fast_io;

    int n;
    cin >> n;
    
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c;
            cin >> c;

            grid[i][j] = (c-'A');
        }
    }

    queue<int> fila;
    vector<int> diag(2*n-1, 100);
    vector<bool> visited(n*n);

    fila.push(0);
    diag[0] = grid[0][0];
    visited[0] = 1;

    vector<vector<int>> last(n, vector<int>(n));

    while(!fila.empty()){
        int xy=fila.front(); fila.pop();
        int x=xy/n, y=xy%n, d=x+y;
        
        if(grid[x][y]>diag[d]) continue;

        for(int k=0; k<2; k++){
            int nx=x+dx[k], ny=y+dy[k];
            
            if(nx<n && ny<n && !visited[nx*n+ny]){
                last[nx][ny] = k;
                fila.push(nx*n+ny);

                visited[nx*n+ny] = 1;
                diag[d+1] = min(diag[d+1], grid[nx][ny]);
            }
        }
    }

    int x=n-1, y=n-1;
    vector<char> resp;

    while(x!=0 || y!=0){
        resp.PB((char)(grid[x][y] + 65));
        int d = last[x][y];
        x -= dx[d];
        y -= dy[d];
    }
    resp.PB((char)(grid[x][y] + 65));

    for(int i=SZ(resp)-1; i>=0; i--) cout << resp[i];
    cout << endl;


    return 0;
}
