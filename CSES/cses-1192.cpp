// 03/11/20 // 7:41 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;

char ma[MAXN][MAXN];
int aux_x[] = {-1, 0, 1, 0, 0};
int aux_y[] = {0, 1, 0, -1, 0};

void dfs(int x, int y){
    ma[x][y] = '#';

    for(int k=0; k<4; k++){
        int new_x = x + aux_x[k];
        int new_y = y + aux_y[k];

        if(ma[new_x][new_y]=='.')
            dfs(new_x, new_y);
    }
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> ma[i][j];

    int cont = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(ma[i][j]=='.'){
                cont++;
                dfs(i, j);
            }
        
    cout << cont << endl;

    return 0;
}
