// 18/04/19 // 3:39 PM //

#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 1000010

int n, m, soma=0,atual=0;
int saldo[MAXN];

int main(){
    cin >> m >> n;

    for(int i=0; i<m; i++){
        int x, v, y;
        cin >> x >> v >> y;

        atual    += v;
        saldo[x] -= v;
        saldo[y] += v;
    }

    for(int i=1; i<=n; i++)
        soma += abs(saldo[i]);
    soma /=2;

    if(soma!=atual)
        cout << "S\n";
    else
        cout << "N\n";

    cout << soma << "\n";

    return 0;
}
