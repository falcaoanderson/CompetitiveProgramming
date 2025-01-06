/*
05/01/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = 100;
const int MAXK = 150;

int n, m, k;
char grid[MAXK][MAXN][MAXN];
int order[MAXK], holes[MAXK];
    
bool check(int z, int i, int j){
    if(z<1 || z>k+1 || i<=1 || i>=n || j<=1 || j>=m){
        cout << "error1" << endl;
        return 0;
    }
    return grid[z][i][j]!=grid[z][i-1][j] && grid[z][i][j]!=grid[z][i+1][j] &&
           grid[z][i][j]!=grid[z][i][j-1] && grid[z][i][j]!=grid[z][i][j+1];
}

bool cmp(int a, int b){
    return holes[a]>holes[b];
}

int main(){
    fast_io;

    cin >> n >> m >> k;

    for(int z=1; z<=k+1; z++){

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> grid[z][i][j];
            }
        } 

        order[z] = z;
        for(int i=2; i<=n-1; i++){
            for(int j=2; j<=m-1; j++){
                if(check(z, i, j)){
                    holes[z]++;
                }
            }
        }
    }

    sort(order+1, order+k+2, cmp);

    vector< pair<int, pair<int, int>> > ops;
    for(int z=1; z<=k; z++){
        int crr=order[z], nxt = order[z+1];

        if(crr<1 || crr>k+1 || nxt<1 || nxt>k+1){
            cout << "error2 " << crr << " "  << nxt << endl;
            break;
        }

        for(int i=2; i<=n-1; i++){
            for(int j=2; j<=m-1; j++){
                if(grid[crr][i][j]!=grid[nxt][i][j]){
                    ops.push_back({1, {i, j}});
                }
            }
        }

        ops.push_back({2, {nxt, -1}});
    }

    cout << order[1] << endl;
    cout << ops.size() << endl;
    for(auto p: ops){
        cout << p.first << " " << p.second.first;
        if(p.first==1) cout << " " << p.second.second;
        cout << endl;
    }

    return 0;
}
