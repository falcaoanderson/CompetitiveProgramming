/*
01/11/23 
Problem: Knight's Tour - CSES Problem Set
Complexity: ? O(fast)
*/

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
#include <cmath>

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

int dx[] = { 2, 2, -2, -2, 1, -1, -1,  1, 0, 0};
int dy[] = {-1, 1, -1,  1, 2,  2, -2, -2, 0, 0};
vector<int> order = {0, 1, 2, 3, 4, 5, 6, 7};

int possible_moves[13][13], grid[13][13];

bool in_grid(int x, int y){
    return (1<=x && x<=8 && 1<=y && y<=8);
}

int cmp_x, cmp_y;
bool cmp(const int& a, const int& b){
    if(!in_grid(dx[a]+cmp_x, dy[a]+cmp_y)) return 0;
    if(!in_grid(dx[b]+cmp_x, dy[b]+cmp_y)) return 1;

    return possible_moves[dx[a]+cmp_x][dy[a]+cmp_y] < possible_moves[dx[b]+cmp_x][dy[b]+cmp_y];
}

int moves=1;
void solve(int x, int y){
    if(moves==64) return;

    cmp_x = x; cmp_y = y;
    sort(order.begin(), order.end(), cmp);

    for(int k: order){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(grid[nx][ny]==0 && in_grid(nx, ny)){
            grid[nx][ny] = (++moves);

            solve(nx, ny);

            if(moves==64) break;
            
            grid[nx][ny] = 0;
            moves--;
        }
    }
}

int main(){
    fast_io;

    int a, b;
    cin >> b >> a;

    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            for(int k=0; k<8; k++){
                possible_moves[i][j] += (int)in_grid(i+dx[k], j+dy[k]);
            }
        }
    }

    grid[a][b] = 1;
    solve(a, b);

    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
