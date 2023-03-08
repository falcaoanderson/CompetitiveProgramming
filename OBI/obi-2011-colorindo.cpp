// 20/10/20 // 10:02 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e2) + 10;

int n, m, ma[MAXN][MAXN];
int aux_x[10] = {-1, -1, -1, 0, 1, 1, 1, 0, 2, 2};
int aux_y[10] = {-1, 0, 1, 1, 1, 0, -1, -1, 2, 2};

int dfs(int x, int y){
    ma[x][y] = 1;

    int cont = 0;
    for(int k=0; k<8; k++){
        int xx = x + aux_x[k];
        int yy = y + aux_y[k];

        if(xx>=1 && xx<=n && yy>=1 && yy<=m && !ma[xx][yy]){
            cont += dfs(xx, yy) + 1;
        }
    }

    return cont;
}

int main(){
    fast_io;
    int x, y, qnt;

    cin >> n >> m >> x >> y >> qnt;

    while(qnt--){
        int a, b;
        cin >> a >> b;
        ma[a][b]=1;
    }

    cout << dfs(x, y)+1 << endl;

    return 0;
}

