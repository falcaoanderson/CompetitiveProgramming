// 10/07/23 //
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

const int MAXN = 7 + 5;

char grid[MAXN][MAXN];
int aux_x[] = {-1, 0, 1, 0, 0, 0};
int aux_y[] = {0, 1, 0, -1, 0, 0};

bool ingrid(int i, int j){
    return (1<=i && i<=7 && 1<=j && j<=7);
}

int main(){
    fast_io;

    for(int i=1; i<=7; i++){
        for(int j=1; j<=7; j++){
            cin >> grid[i][j];
        }
    }

    int resp = 0;

    for(int i=1; i<=7; i++){
        for(int j=1; j<=7; j++){
            if(grid[i][j]!='o') continue;

            for(int k=0; k<4; k++){
                int ax = i + aux_x[k];
                int ay = j + aux_y[k];

                int bx = i + aux_x[(k+2)%4];
                int by = j + aux_y[(k+2)%4];

                if(ingrid(ax, ay) && ingrid(bx, by) && 
                   grid[ax][ay]=='o' && grid[bx][by]=='.') resp++; 
            }
        }
    }

    cout << resp << endl;

    return 0;
}
