// 12/08/19 // 8:05 PM //

#include <iostream>

using namespace std;

#define MAXN 1010

int n, m, q;
long long matriz[MAXN][MAXN];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            cin >> matriz[i][j];
            matriz[i][j] += matriz[i][j-1];
        }

    cin >> q;

    for(int k=0; k<q; k++){
        int i1, j1, i2, j2;
        long long soma=0;

        cin >> i1 >> j1 >> i2 >> j2;

        for(int aux=i1; aux<=i2; aux++)
            soma += matriz[aux][j2] - matriz[aux][j1-1];

        cout << soma << "\n";
    }

    return 0;
}

