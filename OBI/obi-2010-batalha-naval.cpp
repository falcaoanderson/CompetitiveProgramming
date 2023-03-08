// 27/10/20 // 11:20 AM //

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
const int MAXN = (1e2) + 10;

int n, m;
char ma[MAXN][MAXN];
int aux_x[5] = {-1, 0, 1, 0, 0};
int aux_y[5] = {0, 1, 0, -1, 0};

bool dfs(int x, int y){
    ma[x][y] = '.';

    bool flag = 1;
    for(int k=0; k<4; k++){
        int nx = x + aux_x[k];
        int ny = y + aux_y[k];

        if(nx<1 || nx>n || ny<1 || ny>m) continue; // fora do grid

        if(ma[nx][ny]=='#') flag = 0;
        if(ma[nx][ny]=='d') flag = dfs(nx, ny) && flag;
    }

    return flag;
}

int main(){
    fast_io;

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> ma[i][j];

    int k;
    cin >> k;

    while(k--){
        int a, b;
        cin >> a >> b;

        if(ma[a][b]=='#') ma[a][b]='d';
    }   
    //cout << endl << endl;

    int resp = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            if(ma[i][j]=='d'){
                int q = dfs(i, j);
                
                //if(q) cout << i << " " << j << endl;
                
                resp += q;
            }
        }

    cout << resp << endl;

    return 0;
}