/*
28/01/26

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

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e3 + 5;

const vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
const vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m;
int grid[MAXN][MAXN], memo[MAXN][MAXN];
vector<pii> letters[30];

int main(){
    fast_io;

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;

            grid[i][j] = (c - 'A');

            letters[grid[i][j]].PB({i, j});
        }
    }

    int ans = 0;
    for(int i=25; i>=0; i--){
        for(pii p: letters[i]){
            int x = p.FF, y = p.SS;
            memo[x][y] = 1;
            
            for(int k=0; k<8; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(0<=nx && nx<n && 0<=ny && ny<m && grid[nx][ny]==i+1){
                    memo[x][y] = max(memo[x][y], memo[nx][ny] + 1);
                }
            }

            ans = max(ans, memo[x][y]);
        }
    }

    cout << ans << endl;

    return 0;
}