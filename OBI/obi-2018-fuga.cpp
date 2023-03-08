// 22/07/20 // 9:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 15;
const int INF  = 0x3f3f3f3f;

int n, m, xi, yi, xf, yf;
int aux_x[4] = { 0, -1, 0, 1};
int aux_y[4] = {-1,  0, 1, 0};
bool visitado[MAXN][MAXN];

bool is_posible(int i, int j){
    return (i>=1 && i<=n && j>=1 && j<=m);
}

int dfs(int i, int j){
    if(i==xf && j==yf) return 0;

    visitado[i][j] = 1;

    int dist = -INF;

    for(int k=0; k<4; k++){
        int new_i = i + aux_x[k];
        int new_j = j + aux_y[k];

        if(is_posible(new_i, new_j) && !visitado[new_i][new_j])
            dist = max(dist, 1 + dfs(new_i, new_j));

    }

    visitado[i][j] = 0;
    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> xi >> yi >> xf >> yf;

    for(int i=2; i<=n; i+=2)
        for(int j=2; j<=m; j+=2)
            visitado[i][j] = 1;

    cout << dfs(xi, yi) + 1 << endl;

    return 0;
}
