// 13/06/20 // 08:02 PM //

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define endl "\n"
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;

int l, c, a, b;
int ma[MAXN][MAXN];
int aux_x[4] = {-1, 0, 1,  0};
int aux_y[4] = { 0, 1, 0, -1};

void dfs(int x, int y){
    ma[x][y] = 0;

    for(int k=0; k<4; k++){
        int new_x = x + aux_x[k];
        int new_y = y + aux_y[k];

        if(ma[new_x][new_y]==1){
            dfs(new_x, new_y);
            return;
        }
    }

    cout << x << " " << y << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> c >> a >> b;

    for(int i=1; i<=l; i++)
        for(int j=1; j<=c; j++)
            cin >> ma[i][j];

    dfs(a, b);

    return 0;
}
