#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e2+5;

int estoque[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> estoque[i][j];
        }
    }

    int p;
    cin >> p;

    int resp = 0;

    while(p--){
        int i, j;
        cin >> i >> j;

        if(estoque[i][j]>0){
            resp++;
            estoque[i][j]--;
        }
    }

    cout << resp << endl;

    return 0;
}