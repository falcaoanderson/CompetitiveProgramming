// 14/04/20 // 6:42 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = (int)(5e2) + 10;
int n, m;
char ma[MAXN][MAXN];

void dfs(int i, int j){
    ma[i][j] = 'o';
    if(i==n) return;

    if(ma[i+1][j] == '.') dfs(i+1, j);
    if(ma[i+1][j] == '#'){
        if(ma[i][j+1] == '.') dfs(i, j+1);
        if(ma[i][j-1] == '.') dfs(i, j-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int xi, yi;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> ma[i][j];

            if(ma[i][j]=='o'){
                xi = i;
                yi = j;
            }
        }
    }

    dfs(xi, yi);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            cout << ma[i][j];

        cout << endl;
    }

    return 0;
}
