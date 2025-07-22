/*
21/07/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
const int MAXN = (5e2) + 5;
const int MOD  = (1e9) + 7;

int grid[MAXN][MAXN];

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char c;
            cin >> c;

            grid[i][j] = (c=='*'?1:0);
        }
    }

    int cx=-1, cy=-1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(grid[i][j] && grid[i-1][j] && grid[i+1][j] && grid[i][j-1] && grid[i][j+1]){
                cx = i;
                cy = j;
            }
        }
    }
    
    if(cx==-1){
        cout << "NO" << endl;
        return 0;
    }

    vector<bool> flags(4, 1);
    grid[cx][cy] = 2;
    for(int i=1; i<=max(n, m); i++){
        if(flags[0] && cx+i<=n && grid[cx+i][cy]==1) grid[cx+i][cy] = 2;
        else flags[0] = 0;
        if(flags[1] &&cx-i>=1 && grid[cx-i][cy]==1) grid[cx-i][cy] = 2;
        else flags[1] = 0;
        if(flags[2] &&cy+i<=m && grid[cx][cy+i]==1) grid[cx][cy+i] = 2;
        else flags[2] = 0;
        if(flags[3] &&cy-i>=1 && grid[cx][cy-i]==1) grid[cx][cy-i] = 2;
        else flags[3] = 0;
    }

    bool flag = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(grid[i][j]==1) flag = 0;
        }
    }

    cout << (flag?"YES":"NO") << endl;

    return 0;
}
