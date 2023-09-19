// 19/09/23 //
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
#include <functional>

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

const int MAXN = (1e2) + 5;

int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int aux_x[] = {-1, 0, 1, 0, 0, 0};
int aux_y[] = {0, 1, 0, -1, 0, 0};

bool comp(pii a, pii b){
    return grid[a.ff][a.ss]>grid[b.ff][b.ss];
}
int solve(int x, int y){
    priority_queue<pii, vector<pii>, function<bool(pii, pii)> > pqueue(comp);
    memset(visited, 0, sizeof(visited));

    pqueue.emplace(x, y);
    visited[x][y] = 1;

    int qnt = 0;

    while(!pqueue.empty()){
        x = pqueue.top().ff;
        y = pqueue.top().ss;
        pqueue.pop();

        qnt++;

        for(int k=0; k<4; k++){
            int nx = x + aux_x[k];
            int ny = y + aux_y[k];

            if(!visited[nx][ny] && grid[nx][ny]>grid[x][y]){
                visited[nx][ny] = 1;
                pqueue.emplace(nx, ny);
            }
        }
    }

    return qnt;
}

int main(){
    fast_io;

    int r, c;
    cin >> r >> c;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> grid[i][j];
        }
    }

    int resp = 0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            bool flag = 1;
            for(int k=0; k<4; k++){
                int nx = i + aux_x[k];
                int ny = j + aux_y[k];
                if(0<nx && nx<=r && 0<ny && ny<=c && grid[nx][ny]<grid[i][j]){
                    flag = 0;
                    break;
                }
            }

            if(flag)
                resp = max(resp, solve(i, j));
        }
    }

    cout << resp << endl;
    
    return 0;
}
